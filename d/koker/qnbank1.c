 // Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
//koker 99.12.13

inherit ROOM;

int deposit(string arg, object ob);
int check(string arg, object ob);
int withdraw(string arg, object ob);

void create ()
{
  set ("short", "Ç±ÄÜÒøĞĞ");
  set ("long", @LONG

ÕâÊÇÒ»¼ÒÓÉĞÄ¶¯´óÏÀ¿ªÉèµÄÎªÍæ¼Ò´¢´æÇ±ÄÜµÄÒøĞĞ¡£
ÉùÓş·Ç³£ºÃ£¬ÔÚÈ«¹úÖ»ÓĞÒ»¼Ò£¬±ğÎŞ·ÖºÅ¡£ÔÚÄÏÃæ
ÓĞÒ»¿éÓÃÒ»Õû¿é´óÀíÊ¯µñ¿ÌµÄÆÁ·ç¡£ÒøĞĞµÄÃÅ¿Ú¹Ò
ÓĞÒ»¿é»Æ½ğ×öµÄÅÆ×Ó(paizi)¡£

LONG);
  set("item_desc", ([
                "paizi": @TEXT
ÕâÀïÊÇÇ±ÄÜÒøĞĞ£¬Ä¿Ç°ÎÒÃÇÌá¹©µÄ·şÎñÓĞ£º
[33m
qn_cha         ²éÇ±ÄÜ¡£
qn_cun         ´æÇ±ÄÜ¡£
qn_qu          È¡Ç±ÄÜ¡£
[32m
×¢Òâ£ºÉÏÏŞÊÇÒ»Ç§Íò¡£
Áí£º  ½­ºşÅóÓÑÈ¡µÄÊ±ºò»á¿Ûµô0.1%µÄÇ±ÄÜ£¬
      ÖÁÓÚ¾­³£À´µ·ÂÒµÄÂğ£¿ºÙºÙ......
TEXT,
      "pingfeng": "Õâ¸ö´óÀíÊ¯ÆÁ·çËÆºõ¿ÉÒÔÍÆ¿ª(push)¡£\n",
      "ÆÁ·ç" : "Õâ¸ö´óÀíÊ¯ÆÁ·çËÆºõ¿ÉÒÔÍÆ¿ª(push)¡£\n",
      "´óÀíÊ¯ÆÁ·ç" : "Õâ¸ö´óÀíÊ¯ÆÁ·çËÆºõ¿ÉÒÔÍÆ¿ª(push)¡£\n"
        ]) );      
  set("exits", ([ /* sizeof() == 4 */
  "down" : "/d/city/bank",
  
]));
  set("objects", ([ /* sizeof() == 2 */
   "/d/koker/npc/yhguanshi" : 1,
]));
  //set("no_fight", 1);
  set("no_magic", 1);
  setup();

}

void init()
{
//   add_action("do_deposit", "qn_cun")
   add_action("do_check", "qn_cha");
   add_action("do_withdraw", "qn_qu");
   add_action("do_push", "push");
   
}

int do_deposit(string arg, object ob)
{
       string what;
       int amount;
       object what_ob, me,who;
       me = this_player();
       who = this_object();
   
   if(!arg || sscanf(arg, "%d", amount) !=1)
   {
     return notify_fail("ÃüÁî¸ñÊ½£ºqn_cun <ÊıÁ¿>\n");
   } 

         if(((int)me->query("potential")-(int)me->query("learned_points")) < amount)
        {
                return notify_fail("ÄãÃ»ÓĞÕâÃ´¶àÇ±ÄÜ¡£\n");
        }
         
        if(amount<0)  //Ã»ÓĞÕâÒ»ĞĞ£¬ÈôÁË²»ÉÙ»ö¡£cry
        {
        	object *objs = all_inventory(me);
        	int i = sizeof (objs);
        	message_vision ("$NÏë´æÈë¸ºÇ±ÄÜ£¿grin...\n ¿ÕÖĞÍ»È»Éì³öÒ»Ö»½ğ¹¿°ô£¬Ïò$NµÄºóÄÔÔÒÁËÏÂÈ¥¡£\n",me);
        	me->unconcious(); //»è    
                while (i--) //Ã»ÊÕ¶«Î÷
                 {
                    object obj = objs[i];
                    message_vision ("$NÉíÉÏµÄ"+obj->query("name")+"ÄªÃûÆäÃîµÄ·É×ßÁË¡£\n",me);
                    obj->move(me);
                    destruct(obj);
                 }
            	return 1;
        } 
        
  

   
 //       me->start_busy(3);//ÉèÖÃÑÓÊ±
        message_vision(sprintf("$NÄÃ³ö%sµãÇ±ÄÜ£¬´æ½øÁËÒøĞĞ¡£\n",
           chinese_number(amount)), me);
        me->add("qn_balance",amount);
        me->add("potential",-amount);

        me->save();

   return 1;
}

int do_check()
{
   int total = (int)this_player()->query("qn_balance");

   if(!total || total < 0)  {
        this_player()->set("qn_balance", 0);
   return notify_fail("ÕâÏÖÔÚÕâÀïÃ»ÓĞÄãµÄÇ±ÄÜ¡£\n");
   }
   write("ÄúÔÚ±ÖÒøĞĞ¹²´æÓĞ" +
         chinese_number(total) + "µãÇ±ÄÜ¡£\n");

   return 1;
}

int do_withdraw(string arg)
{
   int amount, v, sl,rv;
   string what;
   object me;

   me = this_player();
   sl = me->query("daoluan");

        if (!arg || sscanf(arg, "%d", amount) != 1)
        {
                return notify_fail("ÃüÁî¸ñÊ½£ºqn_qu <ÊıÁ¿>\n");
        }

        if (amount < 1)
        {
                return notify_fail("ÄãÏëÈ¡³ö¶àÉÙÇ±ÄÜ£¿\n");
        }
 
        if ((v = amount) > me->query("qn_balance"))
        {
                return notify_fail("Äã´æµÄÇ±ÄÜ²»¹»È¡¡£\n");
        }
  
        rv = v;

        if(sl<1)
        {
            if(v<1000)
              {
        	v=v-1;
        	me->add("qn_balance",  -rv);
                me->add("potential",v);
                me->save();
                message_vision(sprintf("$N´ÓÒøĞĞÀïÈ¡³ö%sµãÇ±ÄÜ¡£\n", chinese_number(v)),me);
               }             	
             else
              {	
        	sl=1;
                v = v-v*sl/1000; 
                me->add("qn_balance",  -rv);
                me->add("potential",v);
                me->save();
                message_vision(sprintf("$N´ÓÒøĞĞÀïÈ¡³ö%sµãÇ±ÄÜ¡£\n", chinese_number(v)),me);
               } 
          }
 
         if(sl>1)
         {
             if(v<1000)
             {
             	v=v-sl;	
             	me->add("qn_balance",  -rv);
                me->add("potential",v);
                me->save();
                message_vision(sprintf("ÒòÎª$NÀ´Õâµ·ÂÒ¹ı%d´Î,ËùÒÔ$NµÄË°ÂÊÊÇÇ§·ÖÖ®%s.\n",sl,chinese_number(sl)),me);
                message_vision(sprintf("$N´ÓÒøĞĞÀïÈ¡³ö%sµãÇ±ÄÜ¡£\n", chinese_number(v)),me);
              } 
              else
              {	
        	v = v-v*sl/1000; 
         	me->add("qn_balance",  -rv);
                me->add("potential",v);
                me->save();
                message_vision(sprintf("ÒòÎª$NÀ´Õâµ·ÂÒ¹ı%d´Î,ËùÒÔ$NµÄË°ÂÊÊÇÇ§·ÖÖ®%s.\n",sl,chinese_number(sl)),me);
                message_vision(sprintf("$N´ÓÒøĞĞÀïÈ¡³ö%sµãÇ±ÄÜ¡£\n", chinese_number(v)),me);
               }
          }
    return 1;
}


void close_path()
{
        if( !query("exits/north") ) return;
        message("vision",
"´óÀíÊ¯ÆÁ·çÓÖÒÆ»ØÁËÔ­Î»£¬¸Ç×¡ÁË°µÃÅ¡£\n",
                this_object() );
                delete("exits/south");
}


int do_push(string arg)
{
	object me;
	me = this_player();
        if( !arg || arg=="" ) return 0;

        if( arg=="pingfeng" || arg =="ÆÁ·ç" || arg=="´óÀíÊ¯ÆÁ·ç") {
                write("ÄãÍÆ¿ª´óÀíÊ¯ÆÁ·ç£¬");
	if( (int) me->query("force_factor") >= 150 )
		{
		write("ÍÆ¿ªÁËºóÃæÏòÄÏµÄÒ»ÉÈ°µÃÅ¡£\n");
	        if( !query("exits/west") ) {
     		set("exits/south", __DIR__"wenrouxiang");
        	call_out("close_path", 5);
						}
		return 1;	
		}
		else
		write("ÊÔ×ÅÍÆÁËÍÆºóÃæµÄ°µÃÅ£¬µ«Ã»ÓĞÍÆ¿ª¡£\n");
		return 1;
	}
		write("ÄãÒªÍÆ¿ªÊ²Ã´£¿\n");
}

