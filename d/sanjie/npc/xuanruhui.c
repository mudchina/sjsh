// xuanruhui.c ĞşÈç»Ş

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"ĞşÈç»Ş"NOR, ({"xuan ruhui", "xuan"}));
       set("long", "ÖÒÓÚÌìÒ»¹¬£¬Óë´óÊ¦ĞÖ×îÍ¶Ôµ¡£Ï§ÌåÈõ¶à²¡£¬¹ÊÎä¹¦²»¸ß¡£\n");
       set("title", HIC"ÌìÒ»¹¬"NOR);
       set("per", 30);
       set("gender", "ÄĞĞÔ");
       set("age", 63);
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
       set("max_mana", 1500);
       set("mana", 1500);
       set("mana_factor", 120);
       set("combat_exp", 1000000);
       set("daoxing", 1100000);

        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("spells", 100);  
        set_skill("tianmogong", 100);
        set_skill("literate", 80);
        set_skill("sword", 40);  
        set_skill("huxiaojian", 40);
 set_skill("medical", 50);          set_skill("zhaoyangbu", 80);
        set_skill("force", 80);   
        set_skill("huntianforce", 80);

        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("sword", "huxiaojian");
        map_skill("parry", "huxiaojian");
        map_skill("dodge", "zhaoyangbu");

	create_family("Èı½çÉ½", 3, "À¶");
	
	set("inquiry", ([
	"name"     : "ÎÒĞşÈç»ÚÊÇ´¿ÑôÏÈÊ¦ÃÅÏÂµÚÈı¸öµÜ×Ó¡£\n",
	"here"     : "´¿ÑôÏÈÊ¦ÎªÁËÕòÑ¹ÑıÄ§£¬¾ÍÔÚÕâÀï¿ªÉ½Á¢½Ì£¬ÒÔÇóÃğÑı¡£\n",
	"°ËØÔ"     : "ÎÒÕâÀï¾ÍÓĞÒ»¸ö£¬²»¹ıºóÉ½ÊÇ½ûµØ£¬Äã²»ÒªÂÒÈ¥°¡£¡\n",
	]));	
	
	setup();
	carry_object("/d/sanjie/obj/bagua");
	carry_object("/d/sanjie/obj/jinjia")->wear();
	carry_object("/d/sanjie/obj/qinghong")->wield();
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
