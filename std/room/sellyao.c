//Cracked by Roath
// sellyao.c
// modified by mon 2/28/98 and by koker@sjsh 2001
//ÏÂÒ»²½Òª×öµÄÊÇ×÷³ö¸ù¾İÒ©µÄ¹¦ÄÜÀ´ÅĞ¶ÏÒ©µÄ¼ÛÖµ¡£ÔİÇÒÓÃvalueÀ´ÅĞ¶ÏºÃÁË¡£

inherit ROOM;

string *sell_msg = ({
		"ÆÆÆÆÀÃÀÃ£¬Ò»ÎÄ²»Öµ",
		"ÖÊµØµÍÁÓ£¬ÄÑ¿´Ö®¼«",
		"ÓÖÔàÓÖÆÆ£¬³ôÆøÑ¬Ìì",
});

object shop_box;

int query_max_items() {return 50;}
string get_name(string str);

void init()
{
	add_action("do_value", "value");
	add_action("do_sell", "sell");
	add_action("do_buy", "buy");
	add_action("do_list", "list");

	set("no_clean_up", 1);
}
// find the shopbox object for this shop to hold sold items.
object findbox()
{
    if(shop_box && environment(shop_box)==this_object()) 
      return shop_box;

    shop_box=new(__DIR__"shopbox");
    shop_box->move(this_object());
    return shop_box;
}
string value_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 )
		return chinese_number(value) + "ÎÄÇ®";
	else
		return chinese_number(value/100) + "Á½°×Òø"
			+ (value%100? "ÓÖ" + chinese_number(value%100) + "ÎÄÇ®": "");
}

void pay_player(object who, int amount)
{
	object ob;

	if( amount < 1 ) amount = 1;
	if( amount/100 ) {
		ob = new(SILVER_OB);
		ob->set_amount(amount/100);
		if(!ob->move(who))
		  ob->move(environment(who));
		amount %= 100;
	}
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		if(!ob->move(who))
		  ob->move(environment(who));
	}
}

int do_value(string arg)
{
	object ob;
	int value, sale, amount;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("ÄãÒªÄÃÊ²Ã´Ò©Æ·¸øÒ©ÆÌ¹À¼Û£¿\n");

	if( ob->query("money_id") )
		return notify_fail("ÕâÊÇ¡¸Ç®¡¹£¬ÄãÃ»¼û¹ıÂğ£¿\n");

	value = ob->query("value");

	if((amount=ob->query_amount())<10) {
	    if(value>ob->query("base_value")*amount)
		return notify_fail("Õâ"+ob->query("unit")+
			ob->name()+"ÊıÁ¿²»×ã£¬¿ÖÅÂ²»ÖµÇ®£¡\n");
	} 

	sale=ob->query_temp("sale_price");
	if(sale>0 && sale<value) value=sale;

	if( !value) printf("%sÒ»ÎÄ²»Öµ¡£\n", ob->query("name"));
	else 
		printf("%s¼ÛÖµ%s¡£\nÈç¹ûÄúÒªÂôÁË(sell)£¬¿ÉÒÔÄÃµ½%s¡£\n",
			ob->query("name"), value_string(value),
			value_string(value * 80 / 100));

	return 1;
}



int do_sell(string arg)
{
	object ob;
	int value, sale;
	string obj_file;
	int i, oldnum, amount;
	string index;
	mixed no_sell;
	int dest;
	int destroy_after_sell;// 11/15/98 mon
	                       // this is for items such as poisoned containers.
	                       // after sell, will not increase dangpu's 
	                       // inventory, so can't sell then buy back.

	if( this_player()->is_busy() )
		return notify_fail("ÄãÏÖÔÚÕıÃ¦×ÅÄØ¡£\n");

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("ÄãÒªÂôµôÊ²Ã´Ò©µ¤£¿\n");

	if( ob->query("money_id") )	return notify_fail("ÄãÒªÂô¡¸Ç®¡¹£¿\n");

	value = ob->query("value");

	//if((amount=ob->query_amount())>0) {
	//    if(value>ob->query("base_value")*amount)
	//	return notify_fail("Õâ"+ob->query("unit")+
	//		ob->name()+"ÊıÁ¿²»×ã£¬¿ÖÅÂ²»ÖµÇ®£¡\n");
	//} 

	//sale=ob->query_temp("sale_price");
	//if(sale>0 && sale<value) value=sale;
	//if( !value ) return notify_fail("ÕâÑù¶«Î÷²»ÖµÇ®¡£\n");

        //by koker@sjsh 2001 ¶ÔÊôĞÔ²»ÊÇyandanµÄÎïÆ·µÄÅĞ¶Ï¡£
        if(ob->query("drug_type")!="yaocai") 
            return notify_fail("¶Ô²»ÆğĞ¡µê²»ÊÕÒ©Æ·ÒÔÍâµÄÈÎºÎ¶«Î÷¡£\n");    

	// by Snowcat Sep 8 1998 
	no_sell = ob->query("no_sell");
        if(no_sell) {
	   if (stringp(no_sell))
	       return notify_fail((string)no_sell);
	   return notify_fail("¶Ô²»ÆğÎÒÃÇ²»ÄÜÊÕ¹ºÕâ¸ö£¬ËûºÃÏó²»ÊôÓÚ·²¼äµÄ¡£\n");
	}

        index=ob->query("name")+"("+ob->query("id")+")";

	// 11/15/98 mon
	destroy_after_sell=ob->query_temp("destroy_after_sell");

	if(destroy_after_sell) {
	    // not to change the inventory.
	    ob->move(findbox());
	    dest=1;
	} else {
	 if(!findbox()->query_temp("goods/"+index) ){
           findbox()->set_temp("goods/"+index, ob);
	   findbox()->set_temp("numbers/"+index, 1);
	   ob->move(findbox());
	   dest=0;
	 }
	 else {
	   oldnum = findbox()->query_temp("numbers/"+index);
	   if(oldnum>=500)
	       return notify_fail("ÕÆ¹ñµÄËµ£ºÕâÑùÒ©µ¤ÏÖÔÚ´æ»õ"+
		       "Ì«¶à£¬ÔİÊ±²»ÊÕ¹ºÁË¡£\n");
           findbox()->set_temp("numbers/"+index, oldnum+1);
	   dest=1;
	 }
	}

	write("ÕÆ¹ñµÄ³ªµÀ£º"+ sell_msg[random(sizeof(sell_msg))] +
	  ob->query("name") + "Ò»" + ob->query("unit") + "£¬µ±"+
	   value_string(value*80/100)+ "¡£\n");
	message_vision("$N°ÑÉíÉÏµÄ" + ob->query("name") + "Âôµô¡£\n",
		this_player());

	if(dest)
	   destruct(ob);

	this_player()->start_busy(1);
	pay_player(this_player(), value * 80 / 100);

	return 1;
}

int do_list(string arg)
{
   mapping goods;
   string list, *name;
   int i;
   int j=0;
   string tlist;
   object me=this_player();

   if( !mapp(goods = findbox()->query_temp("goods")) )
	  return notify_fail("Ò©ÆÌÄ¿Ç°Ã»ÓĞÈÎºÎÒ©Æ·¿ÉÂô¡£\n");
   name = keys(goods);
   if(!sizeof(goods)) 
	  return notify_fail("Ò©ÆÌÄ¿Ç°Ã»ÓĞÈÎºÎÒ©Æ·¿ÉÂô¡£\n");

   if( !arg )   {
      list = "Äã¿ÉÒÔ¹ºÂòÏÂÁĞÕâĞ©Ò©Æ·£º\n";
      i=sizeof(goods);
      while(i--) {
             if(!goods[name[i]]) {
	       findbox()->delete_temp("numbers/"+name[i]);
	       findbox()->delete_temp("goods/"+name[i]);
	       continue;
             }
	     //mon 2/4/98 because some items may destruct themselves
	     //after being sold.

	     tlist = get_name(name[i]);
	     list += sprintf("%3d  %-30s£º%-20s£º»¹Ê£%s%s\n", ++j, tlist,
	       value_string(goods[name[i]]->query("value")),
	       chinese_number(findbox()->query_temp("numbers/"+name[i])),
	       goods[name[i]]->query("unit") );
      }
      me->start_more(list);
   } else if( arg == "book" )  {
	  list = "";
	  i=sizeof(goods);
	  while(i--) {
             if(!goods[name[i]]) {
	       findbox()->delete_temp("numbers/"+name[i]);
	       findbox()->delete_temp("goods/"+name[i]);
	       continue;
             }

	        if( mapp(goods[name[i]]->query("skill")) )   {
	        tlist = get_name(name[i]);
	        list += sprintf("%4d  %-30s£º%-20s£º»¹Ê£%s%s\n", ++j, tlist,
	          value_string(goods[name[i]]->query("value")),
	          chinese_number(findbox()->query_temp("numbers/"+name[i])),
	          goods[name[i]]->query("unit") );
		 }
	  }
      if( list == "" )
		 write("Ò©ÆÌÄ¿Ç°Ã»ÓĞÕâÖÖÒ©Æ·£®\n");
      else {
	list = "Äã¿ÉÒÔ¹ºÂòÏÂÁĞÕâĞ©Ò©Æ·£º\n"+list;
	me->start_more(list);
      }
   } else if( arg == "drug" )  {
	  list = "";
	  i=sizeof(goods);
	  while(i--) {
             if(!goods[name[i]]) {
	       findbox()->delete_temp("numbers/"+name[i]);
	       findbox()->delete_temp("goods/"+name[i]);
	       continue;
             }
		 if( goods[name[i]]->query("drug_type") )   {
	        tlist = get_name(name[i]);
	        list += sprintf("%4d  %-30s£º%-20s£º»¹Ê£%s%s\n", ++j, tlist,
	          value_string(goods[name[i]]->query("value")),
	          chinese_number(findbox()->query_temp("numbers/"+name[i])),
	          goods[name[i]]->query("unit") );
		 }
	  }
      if( list == "" )
		 write("Ò©ÆÌÄ¿Ç°Ã»ÓĞÕâÖÖÒ©Æ·£®\n");
      else {
	list = "Äã¿ÉÒÔ¹ºÂòÏÂÁĞÕâĞ©Ò©Æ·£º\n"+list;
	me->start_more(list);
      }
   } else if( arg == "axe" || arg == "blade" || arg == "dagger" || 
	arg == "fork" || arg == "hammer" || arg == "spear" || arg == "mace" || arg == "rake" ||
	arg == "staff" || arg == "stick" || arg == "sword" || arg == "whip" ||
	arg == "throwing" )  {
	  list = "";
	  i=sizeof(goods);
	  while(i--) {
             if(!goods[name[i]]) {
	       findbox()->delete_temp("numbers/"+name[i]);
	       findbox()->delete_temp("goods/"+name[i]);
	       continue;
             }

		 if( goods[name[i]]->query("skill_type") == arg )   {
	        tlist = get_name(name[i]);
	        list += sprintf("%4d  %-30s£º%-20s£º»¹Ê£%s%s\n", ++j, tlist,
	          value_string(goods[name[i]]->query("value")),
	          chinese_number(findbox()->query_temp("numbers/"+name[i])),
	          goods[name[i]]->query("unit") );
		 }
	  }
      if( list == "" )
		 write("Ò©ÆÌÄ¿Ç°Ã»ÓĞÕâÖÖÒ©Æ·£®\n");
      else {
	list = "Äã¿ÉÒÔ¹ºÂòÏÂÁĞÕâĞ©Ò©Æ·£º\n"+list;
	me->start_more(list);
      }
   } else if( arg == "archery" )  {
	  list = "";
	  i=sizeof(goods);
	  while(i--) {
             if(!goods[name[i]]) {
	       findbox()->delete_temp("numbers/"+name[i]);
	       findbox()->delete_temp("goods/"+name[i]);
	       continue;
             }
		 if( goods[name[i]]->query("apply/skill_type") == arg )   {
	        tlist = get_name(name[i]);
	        list += sprintf("%4d  %-30s£º%-20s£º»¹Ê£%s%s\n", ++j, tlist,
	          value_string(goods[name[i]]->query("value")),
	          chinese_number(findbox()->query_temp("numbers/"+name[i])),
	          goods[name[i]]->query("unit") );
		 }
	  }
      if( list == "" )
		 write("Ò©ÆÌÄ¿Ç°Ã»ÓĞÕâÖÖÒ©Æ·£®\n");
      else {
	list = "Äã¿ÉÒÔ¹ºÂòÏÂÁĞÕâĞ©Ò©Æ·£º\n"+list;
	me->start_more(list);
      }
   } else if( arg == "armor" || arg == "boots" || arg == "cloth" ||
	 arg == "finger" || arg == "hands" || arg == "head" || arg == "neck" ||
	 arg == "shield" || arg == "surcoat" || arg == "waist" ||
	 arg == "wrists" )   {
	  list = "";
	  i=sizeof(goods);
	  while(i--) {
             if(!goods[name[i]]) {
	       findbox()->delete_temp("numbers/"+name[i]);
	       findbox()->delete_temp("goods/"+name[i]);
	       continue;
             }
		 if( goods[name[i]]->query("armor_type") == arg )   {
	        tlist = get_name(name[i]);
	        list += sprintf("%4d  %-30s£º%-20s£º»¹Ê£%s%s\n", ++j, tlist,
	          value_string(goods[name[i]]->query("value")),
	          chinese_number(findbox()->query_temp("numbers/"+name[i])),
	          goods[name[i]]->query("unit") );
		 }
	  }
      if( list == "" )
		 write("Ò©ÆÌÄ¿Ç°Ã»ÓĞÕâÖÖÒ©Æ·£®\n");
      else {
	list = "Äã¿ÉÒÔ¹ºÂòÏÂÁĞÕâĞ©Ò©Æ·£º\n"+list;
	me->start_more(list);
      }
   } else   {
	  list = "";
	  i=sizeof(goods);
	  while(i--) {
             if(!goods[name[i]]) {
	       findbox()->delete_temp("numbers/"+name[i]);
	       findbox()->delete_temp("goods/"+name[i]);
	       continue;
             }
	     
	     // mon 12/24/99
	     // allow list/buy using item Chinese name which will make
	     // it easier to select the desired one.
		 if( member_array(arg, 
			     goods[name[i]]->parse_command_id_list()) != -1 ||
			 strsrch(name[i], arg)>=0 )   {
	        tlist = get_name(name[i]);
	        list += sprintf("%4d  %-30s£º%-20s£º»¹Ê£%s%s\n", ++j, tlist,
	          value_string(goods[name[i]]->query("value")),
	          chinese_number(findbox()->query_temp("numbers/"+name[i])),
	          goods[name[i]]->query("unit") );
		 }
	  }
      if( list == "" )
		 write("Ò©ÆÌÄ¿Ç°Ã»ÓĞÕâÖÖÒ©Æ·£®\n");
      else {
	list = "Äã¿ÉÒÔ¹ºÂòÏÂÁĞÕâĞ©Ò©Æ·£º\n"+list;
	me->start_more(list);
      }
   }

   return 1;
}


int do_buy(string arg)
{
   mapping goods;
   string *name;
   string fname;
   object obj_file, ob;
   int value, oldnum, afford, order;
   int i, j;
   object* inv;
   string arg1, arg2;

	if( this_player()->is_busy() )
		return notify_fail("ÄãÏÖÔÚÕıÃ¦×ÅÄØ¡£\n");

   if( !arg )  {
	   write("Ö¸Áî¸ñÊ½£ºbuy <Ä³Îï>\n");
	   return 1;
   }

   // players are used to the "buy sth from sb" format.
   if( sscanf(arg, "%s from %s", arg1, arg2) == 2 )   {
	  arg = arg1;
   }

   if( sscanf(arg, "%s %d", fname, order) != 2 )   {
	  fname = arg;
	  order = 1;
   }

   if( !mapp(goods = findbox()->query_temp("goods")) )
	  return notify_fail("Ò©ÆÌÄ¿Ç°Ã»ÓĞÈÎºÎÒ©Æ·¿ÉÂô¡£\n");
   name = keys(goods);
   if(!sizeof(goods)) 
	  return notify_fail("Ò©ÆÌÄ¿Ç°Ã»ÓĞÈÎºÎÒ©Æ·¿ÉÂô¡£\n");

   j = 0;
   i=sizeof(name);
   while(i--) {
          if(!goods[name[i]]) continue;

	  // mon 12/24/99
	  // allow list/buy using item Chinese name which will make
	  // it easier to select the desired one.

	  if( member_array(fname, 
	          goods[name[i]]->parse_command_id_list()) != -1 ||
	      strsrch(name[i], fname)>=0 )  {
	     j++;	 
	  }
	  if( j == order )   {
		  obj_file = goods[name[i]];
          value = obj_file->query("value"); 
          if( !(afford=this_player()->can_afford(value)) )  {
	          write("ÄãÃ»ÓĞ×ã¹»µÄÇ®¡£\n");
	          return 1; 
          }
          else if( afford == 2 )  {
              write("ÄãÃ»ÓĞ×ã¹»µÄÁãÇ®£¬¶øÒøÆ±ÓÖÃ»ÈËÕÒµÃ¿ª¡£\n");
	          return 1;
   		  }

		  ob = new( base_name( obj_file ) ); 
		  ob->set_name(obj_file->query("name"),
		    obj_file->parse_command_id_list());
		    //so that the bought item would be the
		    //same as the one on sale.

   		  if(!ob->move(this_player()))
		    return 0;

   		  this_player()->start_busy(1);

		  arg = obj_file->query("name")+
		    "("+obj_file->query("id")+")";
   		  oldnum = findbox()->query_temp("numbers/"+arg);
   		  if(oldnum == 1)  {
		         destruct(obj_file);
	  		 findbox()->delete_temp("numbers/"+arg);
	  		 findbox()->delete_temp("goods/"+arg);
   		  }
   		  else    {
	  		 findbox()->set_temp("numbers/"+arg, oldnum-1); 
		  }

   		  this_player()->pay_money(value);
		
   		  message_vision("$NÏòÒ©ÆÌÂòÏÂÒ»" +
			ob->query("unit") + ob->query("name") + "¡£\n", this_player() );

		  this_player()->save();
		  return 1;
	  }
   }

   write("Ò©ÆÌÀïÃ»ÓĞÕâÖÖÒ©Æ·¡£\n");

   return 1;
}

// no clean up at hockshop to prevent items lose.
int clean_up()  
{
      return 0;
}

// strip away ansi color code.
// mon 5/7/98
string get_name(string str)
{
    string str1, str2;

    while(sscanf(str,"%s%*sm%s",str1,str2)==3)
	str=str1+str2;
    return str;
}
