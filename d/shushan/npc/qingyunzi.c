//qing yunzi-yushu 2001.2.
inherit NPC;
void create()
{
       set_name("ÇáÔÆ×Ó", ({"qing yunzi", "yunzi", "zi"}));
       set("title", "ÊñÉ½½£ÅÉµÚÈı´úµÜ×Ó");   
       set("gender", "Å®ĞÔ");
       set("age", 32);
       set("attitude", "peaceful");
       set("class", "swordsman");
       set("str", 30);
       set("int", 30);
       set("per", 40);
       set("con", 30);
       set("combat_exp", 500000);
       set("daoxing", 500000);
       set("max_kee", 1000);
       set("max_sen", 1000);
       set("force", 3600);
       set("max_force", 1800);
       set("force_factor", 90);
       set("max_mana", 1800);
       set("mana", 3600);
       set("mana_factor", 90);
	set_skill("zixia-shengong", 150);
	set_skill("yujianshu", 140);
       set_skill("dodge", 160);
       set_skill("literate", 100);
       set_skill("sword", 140);
       set_skill("force", 150);
       set_skill("parry", 150);
       set_skill("spells", 160);
       set_skill("taoism", 160);
       set_skill("sevensteps", 160);
       map_skill("dodge", "sevensteps");
	map_skill("parry", "yujianshu");
	map_skill("sword", "yujianshu");
       map_skill("force", "zixia-shengong");
       map_skill("spells", "taoism");
       create_family("ÊñÉ½½£ÅÉ", 3, "µÜ×Ó");
       setup();
       carry_object("d/obj/cloth/pink_cloth")->wear();
       carry_object("d/obj/weapon/sword/qingfeng")->wield();
}

void attempt_apprentice(object ob)
{

	if( (string)ob->query("family/family_name")=="ÊñÉ½½£ÅÉ" )
	{

		if( (int)ob->query("family/generation") < 3  )
		{
			if ( (string)ob->query("gender") == "ÄĞĞÔ" ) command("say Ê¦Êå¼ûĞ¦ÁË¡£\n");
			else command("say Ê¦¹Ã¼ûĞ¦ÁË¡£\n");
		}
		else if( (int)ob->query("family/generation") ==3  )
		{
			if ( (string)ob->query("gender") == "ÄĞĞÔ" ) command("say Ê¦ĞÖÌ«¿ÍÆøÁË¡£\n");
			else command("say Ê¦ÃÃÌ«¿ÍÆøÁË¡£\n");
		}
		else 
		{
			command("consider");
			command("say ÊÇÄã×Ô¼ºÒª°İµÄ£¬¿É±ğ¹ÖÎÒ°¡!¡£\n");
			command("recruit " + ob->query("id") );
		}
	}
            else
	{
		command("say ºÃ£¬ÎÒÊñÉ½½£ÅÉÒ»ÃÅÈË²Å±²³ö£¬Äã¿ÉµÃ¸øÊ¦¸¸ÕùÆø¡£\n");
		command("recruit " + ob->query("id") );
	}

	return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "swordsman");
                ob->set("title", "ÊñÉ½½£ÅÉµÚËÄ´úµÜ×Ó");
                       }
              return 0;
}

ÿ
