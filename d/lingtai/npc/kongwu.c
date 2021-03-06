// kongwu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIW"灵台圣君"NOR, ({"master shengju", "shengju", "master"}));
       set("long", "中国五千年传奇人物，自盘古开天以来便掌管着所有的武技。\n");
       set("title", HIC"方寸山圣君"NOR);
       set("gender", "男性");
       set("age", 100);
       set("str", 50);
       set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
//       set("rank_info/respect", "大帝");
       set("looking", "玉面多光润，苍髯颌下飘，金睛飞火焰，长目过眉梢。");
       set("max_kee", 6000);
       set("max_gin", 1000);
       set("max_sen", 6000);
       set("force", 6000);
       set("max_force", 3000);
       set("force_factor", 150);
       set("max_mana", 3000);
       set("mana", 6000);
       set("mana_factor", 150);
       set("combat_exp", (random(7)+1)*5500000);
       set("daoxing", (random(6)+2)*7500000);

        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("spells", 200);  
        set_skill("dao", 200);
        set_skill("literate", 200);
        set_skill("sword", 200);  
        set_skill("wuying", 200);
        set_skill("fumobashi", 200);  
        set_skill("mizongbu", 200);
        set_skill("dodge", 200);  
        set_skill("force", 200);   
        set_skill("wuxiangforce", 200);

        map_skill("spells", "dao");
        map_skill("unarmed", "fumobashi");
        map_skill("force", "wuxiangforce");
        map_skill("sword", "wuying");
        map_skill("parry", "wuying");
        map_skill("dodge", "mizongbu");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        (: cast_spell, "feixian" :),
	}) );

	create_family("方寸山三星洞", 1, "尊者");
	
        setup();
        carry_object("/d/lingtai/obj/cloth2")->wear();
        carry_object("/d/lingtai/obj/pifeng")->wear();
        carry_object("/d/lingtai/obj/sword")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="方寸山三星洞") {
	if ((int)ob->query("daoxing") < 500000 ) {
  	command("say 我们降魔除妖之人最重的就是道行，" + RANK_D->query_respect(ob) + "还需多加努力才能早悟大道。\n");
	return;
	}
/*
	if( (int)ob->query("pending/kick_out")) {
	command("say 这位" + RANK_D->query_respect(ob) + "反复无常，老夫不原再收你为徒了！\n");
	command("sigh");
	return;
	}
*/
	if ((int)ob->query_int() < 35) {
	command("say 这位" + RANK_D->query_respect(ob) + "悟性太低，恐怕收了你也难有作为！\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("dao", 1) < 140 ) {
	command("say 这位" + RANK_D->query_respect(ob) + "对我道法领会还不够深，现在收你也是勉为其难，不如作罢！\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say 老夫不收外门弟子，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "taoist");
}

�
