// boydizi.c ÄÐµÜ×Ó

inherit NPC;
#include <ansi.h>


void create()
{
        set_name("ÄÐµÜ×Ó", ({ "dizi","nan dizi"}));
        set("long","¶ëáÒÅÉÏÂÈýÇ§µÜ×ÓÖ®Ò»¡£\n");
        set("gender", "ÄÐÐÔ");
        set("age", 16);
	  set("class","xian");
	  set("title", HIG"¶ëáÒÅÉÏÂÈýÇ§µÜ×Ó"NOR);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 22);
        set("dex", 25);
        set("max_kee", 450);
        set("max_sen", 400);
        set("force", 500);
        set("max_force", 500);
        set("combat_exp", 20000);
        set("score", 1000);
        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("unarmed", 80);
        set_skill("parry", 80);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 5);

        create_family("¶ëáÒÅÉ", 5, "µÜ×Ó");

        setup();
	  carry_object("/d/city/obj/cloth.c")->wear();
           carry_object("/d/emei/obj/mejian")->wield();
}
