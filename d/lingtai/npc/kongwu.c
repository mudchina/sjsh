// kongwu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIW"ÁéÌ¨Ê¥¾ý"NOR, ({"master shengju", "shengju", "master"}));
       set("long", "ÖÐ¹úÎåÇ§Äê´«ÆæÈËÎï£¬×ÔÅÌ¹Å¿ªÌìÒÔÀ´±ãÕÆ¹Ü×ÅËùÓÐµÄÎä¼¼¡£\n");
       set("title", HIC"·½´çÉ½Ê¥¾ý"NOR);
       set("gender", "ÄÐÐÔ");
       set("age", 100);
       set("str", 50);
       set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
//       set("rank_info/respect", "´óµÛ");
       set("looking", "ÓñÃæ¶à¹âÈó£¬²Ô÷×ò¢ÏÂÆ®£¬½ð¾¦·É»ðÑæ£¬³¤Ä¿¹ýÃ¼ÉÒ¡£");
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

	create_family("·½´çÉ½ÈýÐÇ¶´", 1, "×ðÕß");
	
        setup();
        carry_object("/d/lingtai/obj/cloth2")->wear();
        carry_object("/d/lingtai/obj/pifeng")->wear();
        carry_object("/d/lingtai/obj/sword")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="·½´çÉ½ÈýÐÇ¶´") {
	if ((int)ob->query("daoxing") < 500000 ) {
  	command("say ÎÒÃÇ½µÄ§³ýÑýÖ®ÈË×îÖØµÄ¾ÍÊÇµÀÐÐ£¬" + RANK_D->query_respect(ob) + "»¹Ðè¶à¼ÓÅ¬Á¦²ÅÄÜÔçÎò´óµÀ¡£\n");
	return;
	}
/*
	if( (int)ob->query("pending/kick_out")) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "·´¸´ÎÞ³££¬ÀÏ·ò²»Ô­ÔÙÊÕÄãÎªÍ½ÁË£¡\n");
	command("sigh");
	return;
	}
*/
	if ((int)ob->query_int() < 35) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "ÎòÐÔÌ«µÍ£¬¿ÖÅÂÊÕÁËÄãÒ²ÄÑÓÐ×÷Îª£¡\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("dao", 1) < 140 ) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "¶ÔÎÒµÀ·¨Áì»á»¹²»¹»Éî£¬ÏÖÔÚÊÕÄãÒ²ÊÇÃãÎªÆäÄÑ£¬²»Èç×÷°Õ£¡\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) + "¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓÐ³É¡£");
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

ÿ
