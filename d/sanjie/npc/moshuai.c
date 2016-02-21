// moshuai.c Ä§Ë§

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"Ä§Ë§"NOR, ({"mo shuai", "mo"}));
       set("long", "´óÌìÄ§Î¨Ò»´«ÈË£¬÷âÏÂÓÐÁ½´ó¸ßÊÖ¡£\n");
       set("title", HIC"ÌìÄ§¹¬"NOR);
       set("per", 30);
       set("gender", "ÄÐÐÔ");
       set("age", 50);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "µÜ×Ó");
       set("max_kee", 1500);
       set("max_gin", 100);
       set("max_sen", 1500);
       set("force", 1800);
       set("max_force", 1800);
       set("force_factor", 180);
       set("max_mana", 1800);
       set("mana", 1800);
       set("mana_factor", 180);
       set("combat_exp", 1700000);
       set("daoxing", 2100000);

        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("spells", 120);  
        set_skill("tianmogong", 120);
        set_skill("literate", 120);
        set_skill("stick", 120);  
        set_skill("tianyaofa", 120);
        set_skill("zhaoyangbu", 120);
        set_skill("force", 120);   
        set_skill("huntianforce", 120);
        
        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("stick", "tianyaofa");
        map_skill("parry", "tianyaofa");
        map_skill("dodge", "zhaoyangbu");

	create_family("Èý½çÉ½", 2, "À¶");

	set("inquiry", ([
	"name"     : "ÎÒÊÇÄ§Ë§£¬´óÌìÄ§´«ÈË¡£\n",
	"here"     : "ÕâÀïÊÇÌìÄ§¹¬¡£\n",
	]));	
	
	setup();
	carry_object("/d/sanjie/obj/jinjia")->wear();
	carry_object("/d/sanjie/obj/bintiegun")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="ÌìÄ§¹¬") {
	if ((int)ob->query("daoxing") < 100000 ) {
  	command("say ÄãµÄµÀÐÐ»¹²»¹»£¬" + RANK_D->query_respect(ob) + "»¹Ðè¶à¼ÓÅ¬Á¦¡£\n");
	return;
	}

	if( (int)ob->query("pending/kick_out")) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "ÄãÔø±³ÎÒÅÉ£¬ÎÒ²»Ô­ÔÙÊÕÄãÎªÍ½ÁË£¡\n");
	command("sigh");
	return;
	}

	if ((int)ob->query_int() < 25) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "ÎòÐÔÌ«µÍ£¬¿ÖÅÂÊÕÁËÄãÒ²ÄÑÓÐ×÷Îª£¡\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("tianyaofa", 1) < 80 ) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "¶ÔÎÒÌìÑýÍÀÉñ·¨Áì»á»¹²»¹»Éî£¬ÏÖÔÚÊÕÄãÒ²ÊÇÃãÎªÆäÄÑ£¬²»Èç×÷°Õ£¡\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) + "¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓÐ³É¡£");
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
