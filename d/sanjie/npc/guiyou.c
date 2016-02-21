// guiyou.c ¹íÓÄ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"¹íÓÄ"NOR, ({"gui you", "gui"}));
       set("long", "ÊÇ¹íÚ¤µÄÊ¦ĞÖ£¬µ«ºÃÅ®ÈËÓë½ğÇ®£¬Îä¹¦±ÈËûÊ¦µÜ»¹²î¡£\n");
       set("title", HIC"²ØÊ¬µØ"NOR);
       set("per", 30);
       set("gender", "ÄĞĞÔ");
       set("age", 46);
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

        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("spells", 100);  
        set_skill("tianmogong", 100);
        set_skill("literate", 100);
        set_skill("unarmed", 100);  
        set_skill("liushenjue", 100);
        set_skill("zhaoyangbu", 100);
        set_skill("force", 100);   
        set_skill("huntianforce", 100);

        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("unarmed", "liushenjue");
        map_skill("dodge", "zhaoyangbu");

	create_family("Èı½çÉ½", 2, "À¶");

	set("inquiry", ([
	"name"     : "ÎÒÊÇ²ØÊ¬µØ´óµÜ×Ó£¬ÄãÕÒÎÒÓĞÊ²Ã´ÊÂ£¿¡£\n",
	"here"     : "ÕâÀïÊÇ²ØÊ¬µØ£¬ÄãÕâĞ¡×ÓÏë¸ÉÊ²Ã´£¿\n",
	]));	
	
	setup();
	carry_object("/d/sanjie/obj/jinjia")->wear();
}

void attempt_apprentice(object ob, object me)
{
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) +"¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓĞ³É¡£\n");
        command("recruit " + ob->query("id") );
	return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "sanjie");
}

ÿ
