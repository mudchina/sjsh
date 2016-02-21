// leijiang.c À×½«¾ü

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"À×½«¾ü"NOR, ({"lei jiang", "lei"}));
       set("long", "µç½«¾üµÄËÀ¶ÔÍ·£¬ÎªÕþÈ¨¶áÎ»£¬ÂÊÁìÇÝÏÈ·æ¡¢¹ÆÏÈ·æ¡¢¹íÏÈ·æÎªÌìÄ§·þÎñ¡£\n");
       set("title", HIC"ÌìÄ§¹¬"NOR);
       set("per", 30);
       set("gender", "ÄÐÐÔ");
       set("age", 50);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "µÜ×Ó");
       set("max_kee", 1000);
       set("max_gin", 100);
       set("max_sen", 1000);
       set("force", 1200);
       set("max_force", 1200);
       set("force_factor", 120);
       set("max_mana", 1500);
       set("mana", 1500);
       set("mana_factor", 120);
       set("combat_exp", 1000000);
       set("daoxing", 1100000);

        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("spells", 80);  
        set_skill("tianmogong", 80);
        set_skill("literate", 80);
        set_skill("stick", 80);  
        set_skill("tianyaofa", 80);
        set_skill("zhaoyangbu", 80);
        set_skill("force", 80);   
        set_skill("huntianforce", 80);

        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("stick", "tianyaofa");
        map_skill("parry", "tianyaofa");
        map_skill("dodge", "zhaoyangbu");

	create_family("Èý½çÉ½", 3, "À¶");

	set("inquiry", ([
	"name"     : "ÎÒÊÇÄ§Ë§÷âÏÂÁ½´ó¸ßÊÖÖ®Ò»¡£\n",
	"here"     : "ÕâÀïÊÇµç¸®¡£\n",
	]));	
	
	setup();
	carry_object("/d/sanjie/obj/jinjia")->wear();
	carry_object("/d/sanjie/obj/bintiegun")->wield();
}

void attempt_apprentice(object ob, object me)
{
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) +"¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓÐ³É¡£\n");
        command("recruit " + ob->query("id") );
	return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "sanjie");
}

ÿ
