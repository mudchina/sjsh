//puti.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
       set_name(HIW"ÆĞÌá×æÊ¦"NOR, ({"master puti","puti", "master"}));
       set("long", "´ó¾õ½ğÏÉÃ»¹¸×Ë£¬Î÷·½ÃîÏà×æÆĞÌá\n");
       set("title", HIC"Ğ±ÔÂÈıĞÇ"NOR);
       set("gender", "ÄĞĞÔ");
       set("age", 100);
	set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "ÀÏÊ¦×æ");
       set("per", 26);
	set("looking", "ÓñÃæ¶à¹âÈó£¬²Ô÷×ò¢ÏÂÆ®£¬½ğ¾¦·É»ğÑæ£¬³¤Ä¿¹ıÃ¼ÉÒ¡£");
	set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 2500);
       set("force_factor", 150);
       set("max_mana", 2500);
       set("mana", 5000);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
	set("daoxing", 10000000);

       set_skill("literate", 200);
       set_skill("unarmed", 220);
       set_skill("dodge", 220);
       set_skill("parry", 220);
        set_skill("stick", 220);
        set_skill("sword", 220);
	set_skill("liangyi-sword", 180);
        set_skill("spells", 220);
        set_skill("dao", 220);
	set_skill("puti-zhi", 180);
        set_skill("wuxiangforce", 220);
        set_skill("force", 220);
	set_skill("qianjun-bang", 180);
	set_skill("jindouyun", 180);
	map_skill("spells", "dao");
	map_skill("unarmed", "puti-zhi");
	map_skill("force", "wuxiangforce");
	map_skill("stick", "qianjun-bang");
	map_skill("parry", "qianjun-bang");
	map_skill("dodge", "jindouyun");
	map_skill("sword", "liangyi-sword");
	set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
		(: cast_spell, "light" :),
		(: cast_spell, "dingshen" :),
                (: cast_spell, "thunder" :)
        }) );

create_family("·½´çÉ½ÈıĞÇ¶´", 1, "À¶");
setup();

        carry_object("/d/lingtai/obj/pao")->wear();
        carry_object("/d/lingtai/obj/shoe")->wear();
        carry_object("/d/lingtai/obj/putibang")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="·½´çÉ½ÈıĞÇ¶´") {
	if ((int)ob->query("daoxing") < 500000 ) {
  	command("say ÎÒÃÇĞŞÕæÖ®Ê¿×îÖØµÄ¾ÍÊÇµÀĞĞ£¬" + RANK_D->query_respect(ob) + "»¹Ğè¶à¼ÓÅ¬Á¦²ÅÄÜÔçÎò´óµÀ¡£\n");
	return;
	}
/*
	if( (int)ob->query("pending/kick_out")) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "·´¸´ÎŞ³££¬ÀÏ·ò²»Ô­ÔÙÊÕÄãÎªÍ½ÁË£¡\n");
	command("sigh");
	return;
	}
*/
	if ((int)ob->query_int() < 35) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "ÎòĞÔÌ«µÍ£¬¿ÖÅÂÊÕÁËÄãÒ²ÄÑÓĞ×÷Îª£¡\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("dao", 1) < 120 ) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "¶ÔÎÒµÀ¼ÒÏÉ·¨Áì»á»¹²»¹»Éî£¬ÏÖÔÚÊÕÄãÒ²ÊÇÃãÎªÆäÄÑ£¬²»Èç×÷°Õ£¡\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) + "¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓĞ³É¡£");
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
                ob->set("class", "taoist");
}

int accept_fight(object me, object ob)
{	ob=this_player();
	command("say " + RANK_D->query_rude(ob) + "É±ĞÄÌ«ÖØ£¬¿Ö»ö²»¾ÃÒÑ£¡\n");
	return 0;
}
void die()
{

        if( environment() ) {
        message("sound", "\n\nÆĞÌá×æÊ¦Î¢ÖåÃ¼Í·£¬µÀ£ºÕâØË¹ûÊÇ¸öÌì³ÉµØ¾ÍµÄ£¡\n\n", environment());
        command("sigh");
        message("sound", "\nÆĞÌá×æÊ¦ÉíĞÎÒ»×ª£¬»¯×öÇàÑÌ×ßÁË¡£¡£¡£\n\n", environment());
        }

        destruct(this_object());
}

ÿ
