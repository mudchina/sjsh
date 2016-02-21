// wiuxuke.c ò°Ðë¿Í

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"ò°Ðë¿Í"NOR, ({"qiu xuke", "qiu"}));
       set("long", "×ÔÓ×¿àÐÞµÀÊõÑ§Ï°£¬¹¦Á¦½ö´ÎÓÚ´óÊ¦ÐÖ£¬µ«ÎÞ¹ÊÀë¿ªÊ¦ÃÅ£¬ÒôÑ¶È«ÎÞ£¡\n");
       set("title", HIC"ÌìÒ»¹¬"NOR);
       set("per", 30);
       set("gender", "ÄÐÐÔ");
       set("age", 35);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "ÀÏµÀ³¤");
       set("max_kee", 1000);
       set("max_gin", 100);
       set("max_sen", 1000);
       set("force", 1200);
       set("max_force", 1200);
       set("force_factor", 120);
       set("max_mana", 1200);
       set("mana", 1200);
       set("mana_factor", 120);
       set("combat_exp", 1400000);
       set("daoxing", 1500000);

        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("spells", 80);  
        set_skill("tianmogong", 80);
        set_skill("literate", 80);
        set_skill("sword", 120);  
        set_skill("huxiaojian", 120);
        set_skill("zhaoyangbu", 80);
        set_skill("force", 80);   
        set_skill("huntianforce", 80);
        set_skill("unarmed", 120); 
        set_skill("huxiaoquan", 120); 

        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("sword", "huxiaojian");
        map_skill("parry", "huxiaojian");
        map_skill("dodge", "zhaoyangbu");
        map_skill("unarmed", "huxiaoquan");

	create_family("Èý½çÉ½", 3, "À¶");
	
	set("inquiry", ([
	"name"     : "ÎÒ½Ðò°Ðë¿Í£¬²»¹ýÎÒµÄÕæÃû²»ÊÇÕâ¸ö£¬Äã²»ÎÊÒ²°Õ¡£\n",
	"here"     : "ÕâÊÇºóÉ½½ûµØ£¬Ã»ÓÐÅú×¼²»ÄÜ½øÀ´¡£²»¹ýÄã¼ÈÈ»ÒÔµ½£¬Ò²ÊÇÄãµÄÔµ·Ö¡£\n",
	"°ËØÔ"     : "ºóÃæµÄ°ËØÔÍ¼¿ÉÒÔÍ¨ÏòÌìÒ»ÏÉ¸®£¬ÖÁÓÚÄãÓÐÃ»ÓÐÕâ¸ö¸£·Ö£¬¾ÍÒªËæÔµÁË¡£\n",
	]));
	
	setup();
	carry_object("/d/sanjie/obj/jinjia")->wear();
	carry_object("/d/sanjie/obj/qinghong")->wield();
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
