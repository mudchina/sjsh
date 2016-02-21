//Cracked by Roath
// guanyin.c ¹ÛÒôÆĞÈø
// By Dream Dec. 19, 1996

inherit NPC;
inherit F_MASTER;

int do_drop(object, object);

void create()
{
	set_name("¹ÛÒôÆĞÈø", ({ "guanyin pusa", "guanyin", "pusa" }));
	set("title", "¾È¿à¾ÈÄÑ´ó´È´ó±¯");
	set("long", @LONG
ÀíÔ²ËÄµÂ£¬ÖÇÂú½ğÉí¡£Ã¼ÈçĞ¡ÔÂ£¬ÑÛËÆË«ĞÇ¡£À¼ĞÄĞÀ×ÏÖñ£¬
Ş¥ĞÔ°®µÃÌÙ¡£Ëı¾ÍÊÇÂäÙ¤É½ÉÏ´È±¯Ö÷£¬³±Òô¶´Àï»î¹ÛÒô¡£
LONG);
	set("gender", "Å®ĞÔ");
	set("age", 35);
	set("attitude", "peaceful");
	set("rank_info/self", "Æ¶É®");
	set("rank_info/respect", "ÆĞÈøÄïÄï");
	set("class", "bonze");
        	set("str",24);
	set("per",100);//means no rong-mao description.
	set("max_kee", 5000);
	set("max_gin", 5000);
	set("max_sen", 5000);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 145);
	set("max_mana", 3000);
	set("mana", 6000);
	set("mana_factor", 150);
	set("combat_exp", 2000000);
	set("daoxing", 10000000);

        set_skill("literate", 200);
        set_skill("spells", 220);
        set_skill("buddhism", 220);
        set_skill("unarmed", 220);
        set_skill("jienan-zhi", 180);
        set_skill("dodge", 220);
	set_skill("lotusmove", 180);
        set_skill("parry", 220);
        set_skill("force", 220);
        set_skill("lotusforce", 220);
        set_skill("staff", 220);
	set_skill("lunhui-zhang", 180);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
	}) );
	set("inquiry",([
      "¾»Æ¿": "Ç°Ğ©Ìì£¬¸£ĞÇ½èÎÒµÄ¾»Æ¿ÓÃ£¬µ½ÏÖÔÚÒ²Ã»ÓĞ»¹£¬ÄãÈ¥¿´¿´°É¡£" ]));



	//let's use cast bighammer to protect her...weiqi:)
	create_family("ÄÏº£ÆÕÍÓÉ½", 1, "ÆĞÈø");

	setup();
	carry_object("/d/nanhai/obj/jiasha")->wear();
	carry_object("/d/nanhai/obj/nine-ring")->wield();
}

void attempt_apprentice(object ob)
{
	if (!((string)ob->query("bonze/class") =="bonze" )) {
		command("say ÎÒ·ğÃÅÉñÍ¨¹ã´ó£¬" + RANK_D->query_respect(ob) + "Óû³ÉÕı¹û£¬ÏÈÈëÎÒÃÅ¡£\n");
		write("¿´Ñù×Ó¹ÛÒôÆĞÈø¶ÔÄãÎ´Ìê¶È³ö¼ÒÆÄÎª²»¿ì¡£\n");
		return;
	}	
	if (((int)ob->query_skill("buddhism", 1) < 100 )) {
		command("say " + RANK_D->query_respect(ob) + "²»ÔÚ·ğ·¨ÉÏ¿àĞŞ£¬¿ÖÅÂÄÑ³ÉÕı¹û¡£\n");
		return;
	}
	command("pat " + ob->query("id") );
	command("say ºÃ£¡Õâ²ÅÊÇÎÒ·ğÃÅµÄºÃµÜ×Ó¡£Ö»Òª¶à¼ÓÅ¬Á¦£¬¶¨¿ÉÔç³ÉÕı¹û¡£\n");

	command("recruit " + ob->query("id") );
	return;	
}
void die()
{
	int i;
	string file;
	object *inv;

        if( environment() ) {
        message("sound", "\n\n¹ÛÒôÆĞÈøÒ¡Í·Ì¾µÀ£º¸ÕÀëÃÔÕÏ£¬ÓÖÈëÄ§ÕÏ£¬ÊÀ¼ä¼²¿à£¬ºÎÈË¶ÈÖ®£¡\n\n", environment());
        command("sigh");
        message("sound", "\n¹ÛÒôÆĞÈø¼İÏéÔÆ£¬µÇ²ÊÎí£¬¾¶ÍùÎ÷·½È¥ÁË¡£¡£¡£\n\n", environment());
        inv = all_inventory(this_object());
	for(i=0; i<sizeof(inv); i++) {
		if (inv[i]->query("no_drop")) continue;
		do_drop(this_object(), inv[i]);
//		if (stringp(file = find_command("drop")) && 
//			call_other(file, "do_drop", this_object(), inv[i])) ;
	}
	}

	destruct(this_object());
}

int do_drop(object me, object obj) {
  if (obj->move(environment(me))) {
      //d_mana>0 is for "bian". mon 11/05/97
      if((obj->query_temp("d_mana"))>0) {
            if( obj->query_temp("is_living")==1 )
                 message_vision("$N½«$n´Ó±³ÉÏ·ÅÁËÏÂÀ´£¬ÌÉÔÚµØÉÏ¡£\n", me, obj);
            else {
                 message_vision( sprintf("$N¶ªÏÂÒ»%s$n¡£\n",
                 undefinedp(obj->query_temp("unit"))?
	                 "¸ö":obj->query_temp("unit")
                         ), me, obj );
           }
      } else {
           if( obj->is_character() )
                  message_vision("$N½«$n´Ó±³ÉÏ·ÅÁËÏÂÀ´£¬ÌÉÔÚµØÉÏ¡£\n", me, obj);
           else {
             message_vision( sprintf("$N¶ªÏÂÒ»%s$n¡£\n", obj->query("unit")),
                     me, obj );
             if( !obj->query("value") && !obj->value() ) {
                tell_object(me,"ÒòÎªÕâÑù¶«Î÷²¢²»ÖµÇ®£¬ËùÒÔÈËÃÇ²¢²»»á×¢Òâµ½ËüµÄ´æÔÚ
		   ¡£\n");
                destruct(obj);
             }
           }
      }
      return 1;
  }
  return 0;
}


void unconcious()
{
	die();
}

ÿ
