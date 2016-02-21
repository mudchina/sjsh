#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("ºÚÅÛ", ({"heipao"}));
        set("gender", "ÄÐÐÔ" );
        set("age", 33);
        set("title", "ÎÞÌì×ùÏÂÓÒ»¤·¨");
        set("combat_exp", 1500000);
	set("daoxing", 1500000);
              set("long","´ËÄ§ÊÇÎÞÌì×ùÏÂÓÒ»¤·¨£¬ÎªÈËÐ×ºÝ²Ð±©£¬ÊÈÑªÈçÃü¡£Ëû±¾
ÊÇÒ»É½Ñý£¬ºó±»ÎÞÌìÊÕ·þ£¬µÃ¼ºÖØÓÃ£¬ÊÇÎÞÌì±Ø²»¿ÉÉÙµÄ
¹ô×ÓÊÖ¡£\n");
        set("attitude", "peaceful");
	set("int", 25);
	set("class", "mo");
        create_family("Ä§½ç", 2, "µÜ×Ó");
	
        set("eff_dx", 30000);
        set("nkgain", 200);

        set_skill("unarmed", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_skill("spells", 280);  
        set_skill("molianspells", 280);
        set_skill("literate", 280);
        set_skill("sword", 280);  
        set_skill("xueling-jian", 280);
        set_skill("shifo-zhi", 280);  
        set_skill("moshenbu", 280);
        set_skill("dodge", 280);  
        set_skill("force", 280);   
        set_skill("heilianforce", 280);

        map_skill("spells", "molianspells");
        map_skill("unarmed", "shifo-zhi");
        map_skill("force", "heilianforce");
        map_skill("sword", "xueling-jian");
        map_skill("parry", "xueling-jian");
        map_skill("dodge", "moshenbu");


        set("per", 30);
        set("max_kee", 2500);
        set("max_sen", 2500);
        set("force", 2500);
        set("max_force", 2500);
        set("force_factor", 50);
        set("mana", 2500);
        set("max_mana", 2500);
        set("mana_factor", 50);

        setup();
        carry_object("/d/mojie/obj/tongjia")->wear();
        carry_object("/d/mojie/obj/sword")->wield();
}
void attempt_apprentice(object ob, object me)
{
        if( (int)ob->query_skill("molianforce", 1) < 120 ) {
        command("say ÕâÎ»" + RANK_D->query_respect(ob) + "¶ÔÎÒÄ§µÀÄÚ¹¦Áì»á»¹²»¹»Éî£¬ÏÖÔÚÊÕÄãÒ²ÊÇÃãÎªÆäÄÑ£¬²»Èç×÷°Õ£¡\n");              
        return;
        }
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) +
"¼ÓÈëÄ§½çÒÔºó¶à¼ÓÅ¬Á¦£¬ËûÈÕÎªÉ±ÈçÀ´×ö³öÄãµÄ¹±Ï×¡£\n");
        command("recruit " + ob->query("id") );
            ob->set("title", HIC"Ä§½çÓÒ»¤·¨×ùÏÂµÜ×Ó"NOR);
	return;
}		

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "mo");
}

ÿ
