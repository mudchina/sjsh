// xiangyu.c ÏîÓğ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIW"ÏîÓğ"NOR, ({"xiang yu", "xiang"}));
       set("long", "Ò»´úèÉĞÛ£¬°ÜÓÚÁõ°î£¬ĞÄÉúÔ¹ºŞ£¬Ç§ÄêÀ´Ô©»ê²»Ï¢¡£\n");
       set("title", HIC"À×µ¶ÃÅ"NOR);
       set("per", 30);
       set("gender", "ÄĞĞÔ");
       set("age", 100);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "¹í»ê");
       set("max_kee", 2000);
       set("max_gin", 100);
       set("max_sen", 2000);
       set("force", 2400);
       set("max_force", 2400);
       set("force_factor", 240);
       set("max_mana", 2400);
       set("mana", 2400);
       set("mana_factor", 240);
       set("combat_exp", 2400000);
       set("daoxing", 3500000);

        set_skill("dodge", 160);
        set_skill("parry", 160);
        set_skill("spells", 160);  
        set_skill("tianmogong", 160);
        set_skill("literate", 160);
        set_skill("blade", 200);  
        set_skill("zileidao", 200);
        set_skill("zhaoyangbu", 160);
        set_skill("force", 160);   
        set_skill("huntianforce", 160);
        
        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("blade", "zileidao");
        map_skill("parry", "zileidao");
        map_skill("dodge", "zhaoyangbu");

	create_family("Èı½çÉ½", 1, "À¶");
	
	set("chat_msg_combat", ({
        (: perform_action, "blade", "tulong" :),
        }) );

	set("inquiry", ([
	"name"     : "ÎÒÊÇÏîÓğ£¬µ±Äê°Ü¸øÁõ°î£¬ÎÒÊÄÒª³ğ¡£\n",
	"here"     : "ÕâÀïÊÇÎÚ½­±ß£¬µ±ÄêÎÒ×ÔÉ±µÄµØ·½¡£\n",
	]));	
	
	setup();
	carry_object("/d/sanjie/obj/jinjia")->wear();
	carry_object("/d/sanjie/obj/leidao")->wield();
}

void attempt_apprentice(object ob, object me)
{
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) +"¶à¼ÓÅ¬Á¦£¬ËûÈÕ°ïÎÒ±¨³ğ¡£\n");
        command("recruit " + ob->query("id") );
	return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "sanjie");
}

void xiangyu_disappear (object me)
{
  message_vision (MAG"$NÂıÂıµØ»¯Îª×ÏÉ«ÔÆÎíÏûÊ§ÁË¡£\n"NOR,me);
  destruct (me);
  return;
}

ÿ
