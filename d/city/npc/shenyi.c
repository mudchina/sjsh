//shenyi.c »ªÙ¢ÀÏÏÉ

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW"»ªÙ¢ÀÏÏÉ"NOR, ({"master huatuo", "master"}));
       set("long", "¾ÈÊÀ¼ÃÈËµÄÉñÏÉ¡£\n");
       set("title", HIC"¾ÈÊÀ¼ÃÈË"NOR);
       set("per", 40);
       set("gender", "ÄĞĞÔ");
       set("age", 1000);
        set("attitude", "peaceful");

        set("combat_exp", 20000000);
        set("daoxing", 500000);
        set("shen_type", 1);
        set("max_kee", 2000);
        set("max_gin", 1000);
        set("max_sen", 2000);
	set("max_force", 8888);
	set("force", 8888);
        set("max_mana", 8888);
	set("mana", 8888);
	set("force_factor", 200);
        set_skill("medical", 800);

        set("inquiry", ([
	"name"     : "ÀÏ·òÄËÒ»½é²¼ÒÂ£¬¡£\n",
	"here"     : "´ËÄË¼ÃÊÀÌÃ£¬×¨¸øÌìÏÂ²ÔÉúÖÎ²¡µÄµØ·½£®\n",
	//"ÏÉÒ©"     : (: ask_me :),
	]));
	setup();
        carry_object("/d/obj/cloth/linen")->wear();
}

int recognize_apprentice(object ob)
{ob=this_player();
if ((int)ob->query("level") < 5 ) {
        command("say ÄãµÄµÈ¼¶²»¹»5¼¶£¬" + RANK_D->query_respect(ob) + "»¹Ğè¶à¼ÓÅ¬Á¦¡£\n");
	return 1;
	}
	return 1;
}

ÿ
