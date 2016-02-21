#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("ÉßÄ§", ({"she mo", "mo"}));
        set("gender", "ÄÐÐÔ" );
        set("age", 33);
        set("title", "Ä§½çÁùÁé½«");
        set("combat_exp", 500000);
	set("daoxing", 500000);

        set("attitude", "peaceful");
	set("int", 25);
	set("class", "mo");
        create_family("Ä§½ç", 3, "µÜ×Ó");
	
        set("eff_dx", 30000);
        set("nkgain", 200);

        set_skill("unarmed", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("spells", 120);  
        set_skill("molianspells", 120);
        set_skill("literate", 120);
        set_skill("whip", 120);  
        set_skill("liudu-whip", 120);
        set_skill("shifo-zhi", 120);  
        set_skill("moshenbu", 120);
        set_skill("dodge", 120);  
        set_skill("force", 120);   
        set_skill("heilianforce", 120);

        map_skill("spells", "molianspells");
        map_skill("unarmed", "shifo-zhi");
        map_skill("force", "heilianforce");
        map_skill("whip", "liudu-whip");
        map_skill("parry", "liudu-whip");
        map_skill("dodge", "moshenbu");


        set("per", 30);
        set("max_kee", 500);
        set("max_gin", 500);
        set("max_sen", 500);
        set("force", 1500);
        set("max_force", 1500);
        set("force_factor", 50);
        set("mana", 1500);
        set("max_mana", 1500);
        set("mana_factor", 50);

        setup();
        carry_object("/d/mojie/obj/tongjia")->wear();
        carry_object("/d/mojie/obj/whip")->wield();
}
void attempt_apprentice(object ob, object me)
{
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) +
"¼ÓÈëÄ§½çÒÔºó¶à¼ÓÅ¬Á¦£¬ËûÈÕÎªÉ±ÈçÀ´×ö³öÄãµÄ¹±Ï×¡£\n");
        command("recruit " + ob->query("id") );
	return;
}		

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "mo");
}

ÿ
