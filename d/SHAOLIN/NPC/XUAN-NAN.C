//gunseng.c
#include <ansi.h>

int ask_name(); 

inherit NPC;
inherit F_MASTER;
void create()
{

	set_name("玄难大师", ({
                "xuannan dashi",
                "xuannan",
		"dashi",
	}));
        set("gender", "男性" );
        create_family("少林寺", 2, "弟子");
        set("title",HIY"嵩山少林寺般若堂首座"NOR );
        set("age", 70);
set("long",
		"他是一位白须白眉的老僧，身穿一袭银丝棕黄袈裟。他身材极瘦，\n"
		"两手更象鸡爪一样。他双目微闭，一副没精打采的模样。\n"
	);
	set("class", "bonze");
	set("attitude", "heroism");

        set("force", 3000);
        set("max_force", 3000);
        set("force_factor", 50);
        set("mana", 2000);
        set("max_mana", 3000);
        set("mana_factor", 20);
        set("combat_exp", 1800000);
        set("daoxing", 2500000);

        set_skill("yijinjing", 300);
        set_skill("chanzong", 300);
        set_skill("spells", 300);
        set_skill("force", 300);
        set_skill("dodge", 280);
        set_skill("shaolin-shenfa", 280);
        set_skill("sword", 280);
        set_skill("shaolin-sword", 280);
        set_skill("parry", 280);
        map_skill("dodge", "shaolin-shenfa");
        map_skill("sword", "shaolin-sword");
        map_skill("parry", "shaolin-sword");
        map_skill("force", "yijinjing");
        map_skill("spells", "chanzong");

	set("max_kee", 1300);
	set("max_sen", 1300);
	setup();
        carry_object("/d/shaolin/obj/fumo-sword")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();


}
void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");
	name = ob->query("name");

        if( (string)ob->query("gender") != "男性" )
	{
		command ("say 阿弥陀佛！女施主呀，贫僧可不敢开这等玩笑啊。");
		return;
        }

          if( (int)ob->query_skill("yijinjing",1) < 180)
        {
	command("say " + RANK_D->query_respect(ob) + "，你易筋经修为不够，不能越级拜师。");
                return;
        }

        if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林寺")
	{
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}

        if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林寺") 
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
		return;
	}

	command("say 阿弥陀佛，善哉！善哉！");
        command("recruit " + ob->query("id"));
        ob->set("title", HIY"嵩山少林寺罗汉堂大弟子"NOR);
}
