// guiming.c ¹íÚ¤

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIW"¹íÚ¤"NOR, ({"master guiming", "master"}));
       set("long", "ÊÇ¹íÓÄÊ¦µÜ£¬²»¹ýËûÇÚÓÚÁ·¹¦£¬¹¦·ò±ÈËûÊ¦µÜÇ¿¶àÁË¡£\n");
       set("title", HIC"²ØÊ¬µØ"NOR);
       set("per", 40);
       set("gender", "ÄÐÐÔ");
       set("age", 400);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "¹íÍõ");
       set("max_kee", 2000);
       set("max_gin", 100);
       set("max_sen", 2000);
       set("force", 3000);
       set("max_force", 3000);
       set("force_factor", 300);
       set("max_mana", 2400);
       set("mana", 2400);
       set("mana_factor", 270);
       set("combat_exp", 2400000);
       set("daoxing", 3500000);

        set_skill("dodge", 160);
        set_skill("parry", 200);  
        set_skill("tianmogong", 160);
        set_skill("literate", 200);
        set_skill("unarmed", 200);  
        set_skill("liushenjue", 200);
        set_skill("zhaoyangbu", 160);
        set_skill("force", 200);   
        set_skill("huntianforce", 200);

        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("sword", "liushenjue");
        map_skill("dodge", "zhaoyangbu");
        
        set("chat_msg_combat", ({
		(: cast_spell, "zhui" :),
        }) );

	create_family("Èý½çÉ½", 1, "À¶");
	
	set("inquiry", ([
	"name"     : "ÀÏ·òÄË¹íÚ¤£¬¹íÓÄÊ¦µÜ¡£\n",
	"here"     : "´ËÄË²ØÊ¬µØ£¬Ã»ÓÐÆäËûÊÂÇé±ðÂÒÅÜ¡£\n",
	]));
	
	set("time", 1);
	
	setup();
	carry_object("/d/sanjie/obj/jinjia")->wear();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="Èý½çÉ½") {
	if ((int)ob->query("daoxing") < 500000 ) {
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
	if( (int)ob->query_skill("huntianforce", 1) < 100 ) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "¶Ô»ìÌì±¦¼øÁì»á»¹²»¹»Éî£¬ÏÖÔÚÊÕÄãÒ²ÊÇÃãÎªÆäÄÑ£¬²»Èç×÷°Õ£¡\n");
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
