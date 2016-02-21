// guixianfeng.c ¹íÏÈ·æ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"¹íÏÈ·æ"NOR, ({"gui xianfeng", "gui"}));
       set("long", "À×½«¾ü÷âÏÂÒ»ÃûÏÈ·æ£¬ÉÆÓÃÑı·¨¡£\n");
       set("title", HIC"ÌìÄ§¹¬"NOR);
       set("per", 30);
       set("gender", "ÄĞĞÔ");
       set("age", 30);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "µÜ×Ó");
       set("max_kee", 1000);
       set("max_gin", 100);
       set("max_sen", 1000);
       set("force", 400);
       set("max_force", 400);
       set("force_factor", 20);
       set("combat_exp", 1000000);
       set("daoxing", 1100000);

        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("sword", 80);  
        set_skill("force", 80);   

	set("inquiry", ([
	"name"     : "ÎÒÊÇÀ×½«¾ü÷âÏÂÈı´ó¸ßÊÖÖ®Ò»¡£\n",
	"here"     : "ÕâÀïÊÇÀ×¸®¡£\n",
	]));	
	
	setup();
	carry_object("/d/sanjie/obj/jinjia")->wear();
	carry_object("/d/sanjie/obj/qinghong")->wield();
}

ÿ
