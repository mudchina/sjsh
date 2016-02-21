// datianmo.c ´óÌìÄ§

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIW"¶ÏÑôĞ°Éñ"NOR, ({"duanyang xieshen", "xieshen","shen"}));
       set("long", "Èı½çÄ§Í·Ö®Ò»,ºÜÊÇÀ÷º¦¡£\n");
       set("title", HIC"ÈıÖØÃÅÉñÖ®"NOR);
       set("per", 30);
       set("gender", "ÄĞĞÔ");
       set("age", 3000);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "ÀÏÄ§Í·");
       set("max_kee", 2000);
       set("max_gin", 100);
       set("max_sen", 2000);
       set("force", 2400);
       set("max_force", 2400);
       set("force_factor", 240);
       set("max_mana", 3000);
       set("mana", 3000);
       set("mana_factor", 30);
       set("combat_exp", 2400000);
       set("daoxing", 3500000);

        set_skill("dodge", 350);
        set_skill("parry", 350);
        set_skill("spells", 350);  
        set_skill("tianmogong", 350);
        set_skill("literate", 350);
        set_skill("stick", 350);  
        set_skill("tianyaofa", 350);
        set_skill("zhaoyangbu", 350);
        set_skill("force", 350);   
        set_skill("huntianforce", 350);
        
        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("stick", "tianyaofa");
        map_skill("parry", "tianyaofa");
        map_skill("dodge", "zhaoyangbu");
        
        set("chat_msg_combat", ({
		(: cast_spell, "zhui" :),
        }) );

        create_family("Èı½çÉ½", 1, "À¶");

	set("inquiry", ([
        "name"     : "±İÉñÈıÖØÃÅËùÊô,ÆäËûÍâÊÂÒ»¸Å²»ÎŞÀÏ·ò¹ØÁª¡£\n",
        "here"     : "´ËµØ±ãÊÇÈıÖØÃÅÖ®µÚÒ»´óÃÅ---¶ÏÑôÃÅ¡£\n",
	]));	
	
	setup();
	carry_object("/d/sanjie/obj/jinjia")->wear();
	carry_object("/d/sanjie/obj/shihun")->wield();
//        carry_object("/d/milin/obj/dyd");
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="Èı½çÉ½") {
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
	if( (int)ob->query_skill("tianyaofa", 1) < 120 ) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "¶ÔÎÒÌìÑıÍÀÉñ·¨Áì»á»¹²»¹»Éî£¬ÏÖÔÚÊÕÄãÒ²ÊÇÃãÎªÆäÄÑ£¬²»Èç×÷°Õ£¡\n");
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

ÿ
