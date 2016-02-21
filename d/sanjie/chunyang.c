// chunyang.c ´¿Ñô×æÊ¦

#include <ansi.h>
string ask_me();

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIW"´¿Ñô×æÊ¦"NOR, ({"master zhaoyang", "master"}));
       set("long", "ÌìÒ»¹¬´´½ÌÈË£¬ËÄ°ÙÄêÇ°ÔøÒ»ÈËÖ®Á¦Ãğ¾¡ÖĞÍÁÑıÄ§¡£\n");
       set("title", HIC"ÌìÒ»¹¬"NOR);
       set("per", 40);
       set("gender", "ÄĞĞÔ");
       set("age", 400);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "ÀÏ×æÊ¦");
       set("max_kee", 2000);
       set("max_gin", 100);
       set("max_sen", 2000);
       set("force", 2400);
       set("max_force", 2400);
       set("force_factor", 240);
       set("max_mana", 2400);
       set("mana", 2400);
       set("mana_factor", 270);
       set("combat_exp", 2400000);
       set("daoxing", 3500000);

        set_skill("dodge", 200);
        set_skill("parry", 160);
        set_skill("spells", 160);  
        set_skill("tianmogong", 160);
        set_skill("literate", 160);
        set_skill("sword", 200);  
        set_skill("huxiaojian", 200);
        set_skill("zhaoyangbu", 200);
        set_skill("force", 160);   
        set_skill("huntianforce", 160);

        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("sword", "huxiaojian");
        map_skill("parry", "huxiaojian");
        map_skill("dodge", "zhaoyangbu");
        
        set("chat_msg_combat", ({
		(: cast_spell, "zhui" :),
        }) );

	create_family("ÌìÒ»¹¬", 1, "À¶");
	
	set("inquiry", ([
	"name"     : "ÀÏ·òÄËÌìÒ»¹¬´´ÅÉÈË¡ª¡ª¹ù´¿Ñô¡£\n",
	"here"     : "´ËÄËÌìÒ»ÏÉ¸®Ò²£¬ÄÜ½øÀ´£¬Ò²ËãÄã¸£Ôó²»Ç³¡£\n",
	"ÄÚµ¤"     : (: ask_me :),
	]));
	
	set("time", 1);
	
	setup();
	carry_object("/d/sanjie/obj/xuantian");	
	carry_object("/d/sanjie/obj/jinjia")->wear();
	carry_object("/d/sanjie/obj/chunyang")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="ÌìÒ»¹¬") {
	if ((int)ob->query("daoxing") < 500000 ) {
  	command("say ÄãµÄµÀĞĞ»¹²»¹»£¬" + RANK_D->query_respect(ob) + "»¹Ğè¶à¼ÓÅ¬Á¦¡£\n");
	return;
	}

	if( (int)ob->query("pending/kick_out")) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "ÄãÔø±³ÎÒÅÉ£¬ÎÒ²»Ô­ÔÙÊÕÄãÎªÍ½ÁË£¡\n");
	command("sigh");
	return;
	}

	if ((int)ob->query_int() < 35) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "ÎòĞÔÌ«µÍ£¬¿ÖÅÂÊÕÁËÄãÒ²ÄÑÓĞ×÷Îª£¡\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("huntianforce", 1) < 120 ) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "¶Ô»ìÌì±¦¼øÁì»á»¹²»¹»Éî£¬ÏÖÔÚÊÕÄãÒ²ÊÇÃãÎªÆäÄÑ£¬²»Èç×÷°Õ£¡\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) + "¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓĞ³É¡£");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say ÀÏ·ò²»ÊÕÍâÃÅµÜ×Ó£¬" + RANK_D->query_respect(ob) + "»¹ÊÇÁíÑ°ËûÈË°É£¡\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "sanjie");
}

string ask_me()
{
        object ob;
           
   if((int)this_player()->query("combat_exp") < 30000 )
     return "Äã¹¦Á¦ÉĞÇ³£¬ÅÂÉËÄãĞÔÃü£¬ÒÔºóÔÙËµ°É£¡\n";

   if (this_object()->is_fighting())
     return "Ã»¼ûÀÏ·òÕı´ò×ÅÂğ£¬ÒÔºóÔÙËµ°É£¡\n";

   if ( present("neidan", this_player()) )
     return "³Ô£¬³Ô£¬³Ô£¬ÅÂÄãµ¤ÌïÊÜ²»ÁË£¬Îä¹¦È«·Ï£¡\n";

        if ( present("neidan", environment()) )
     return "ÄÇ²»ÊÇÓĞÒ»¿ÅÄØÂï£¬³ÔÍêÔÙËµ£¡\n";

   if(query("time") <1 )
     return "²»ÇÉ£¬²»ÇÉ£¬ÎÒÒ²Ã»ÁË£¡\n";

     say("´¿ÑôÏÈÊ¦ËµµÀ£ºÄÇµ½ÒªÇÆÄã¹»²»¹»¸ñ³ÔÁË£¬·ÅÂí¹ıÀ´°É£¡\n");
     this_player()->set_temp("chunyang_fight", 1);
     return ("ºÙºÙ£¡\n");
}

int accept_fight(object who)
{
     object me;
    me = this_object();
     if (!who->query_temp("chunyang_fight")){
     command("say ²»´ò²»´ò£¬Ã»¼ûÀÏ·òÕı´ò×ÅÂğ£¡\n");
         return 0;
   }
     if (me->is_fighting()){
     command("say ²»´ò²»´ò£¡\n");
         return 0;
   }
   say("´¿ÑôĞ¦µÀ£ºÀÏÍ·×ÓµÈÁË¼¸°ÙÄêÁË£¬ËãÊÇµÈµ½Ò»¸öÓĞ³öÏ¢µÄ£¡\n");
   me->set("eff_kee", (int)me->query("max_kee"));
        me->set("kee", (int)me->query("max_kee"));
        me->set("eff_sen", (int)me->query("max_sen"));
        me->set("sen", (int)me->query("max_sen"));

     who->set_temp("chunyang_fight",0);
     remove_call_out("check_fight");
     call_out("check_fight", 1, me, who);
     return 1;
}

void player_win (object me, object who)
{
     object obj;
   if (me->query("time")<=0)
     return;
   obj=new("/d/sanjie/obj/neidan");
   say("´¿ÑôÏÈÊ¦ÑöÌì´óĞ¦£º¹ş¹ş¹ş¡­¡­µÈÁË¼¸°ÙÄêÁË£¬ÖÕÓÚÕÒµ½¼Ì³ĞÈËÁË£¡\n");
   say("Èç´ËÎäÒÕ¸ßÇ¿£¬ÕæÊÇÁîÎÒµÈÅå·ş°¡£¡\n");
   obj->move(who);
        me->add("time", -1);
   message_vision("´¿ÑôÏÈÊ¦¶Ô$N¹ş¹şĞ¦µÀ£ºÏÖÔÚÎÒ¾Í´«ÄãÀÏ·òµÄËÄ°ÙÄê¹¦Á¦£¬ÄãÊÕÏÂ°É£¡\n", who);
   call_out("reg", 750);
}

int reg()
{
   object me=this_object();
   me->set("time", 1);
   return 1;
}

void player_lose (object me, object who)
{
     string msg;
     msg = RANK_D->query_respect(who);
   
   command("jump");
   say("´¿ÑôÏÈÊ¦¹ş¹ş´óĞ¦£º"+msg+"ÄªÒª²»¸ßĞË£¬»ØÈ¥ºÃºÃÁ·Îä°É£¬À´ÈÕ·½³¤Âï£¡\n");
}

void check_fight (object me, object who)
{
     int my_kee, whos_kee;
     int my_max_kee, whos_max_kee;

   if(!who) return;
     my_kee = me->query("kee");
     whos_kee = who->query("kee");
     my_max_kee = me->query("max_kee");
     whos_max_kee = who->query("max_kee");

     if (me->is_fighting()){
         remove_call_out("check_fight");
         call_out ("check_fight",1,me,who);
         return;
     }

   if (!present(who, environment(me)))
         return;

   if ((my_kee*100/my_max_kee) <= 50)
     player_win (me, who);
     else if ((whos_kee*100/whos_max_kee) <= 50)
     player_lose (me, who);
}

ÿ
