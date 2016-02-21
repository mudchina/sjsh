//Cracked by Roath
// tieguaili.c...weiqi, 98.02.24.

inherit NPC;
void create()
{
	set_name("Ìú¹ÕÀî", ({"tieguai li", "tieguai", "li"}));
	//set("title", "");
	set("gender", "ÄÐÐÔ" );
	set("age", 42);
	set("per", 12);
	set("long", "Ëû½ÅµÇÒ»Ë«ÀÃ²ÝÐ¬£¬Éí×ÅÒ»¼þÔç¾ÍÃ»ÁË±¾À´ÃæÄ¿µÄÔàÅÛ£¬×ìÀïºß×Å×ßµ÷Ð¡Çú£¬Ò»¸±ÓÆÏÐÉñÌ¬¡£\n");
	set("class", "xian");
	set("combat_exp", 120000);
  set("daoxing", 300000);

	set("attitude", "peaceful");
	create_family("Îå×¯¹Û", 3, "µÜ×Ó");
	set_skill("unarmed", 60);
	set_skill("wuxing-quan", 60);
	set_skill("dodge", 80);
	set_skill("baguazhen", 80);
	set_skill("parry", 80);
	set_skill("staff", 90);
	set_skill("fumo-zhang", 100);
	set_skill("force", 70);   
	set_skill("zhenyuan-force", 70);
	set_skill("literate", 20);
	set_skill("spells", 80);
	set_skill("taiyi", 80);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("staff", "fumo-zhang");
	map_skill("dodge", "baguazhen");

	set("max_kee", 500);
	set("max_sen", 500);
	set("force", 1000);
	set("max_force", 800);
	set("mana", 1600);
	set("max_mana", 800);	
	set("force_factor", 40);
	set("mana_factor", 40);

	setup();
	carry_object("/d/obj/cloth/pobuyi")->wear();
	carry_object("/d/obj/cloth/lancaoxie")->wear();
	carry_object("/d/obj/weapon/staff/tieguai")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="Îå×¯¹Û" )
	{
		if( (int)ob->query("family/generation") < 3  )
		{
			if ( (string)ob->query("gender") == "ÄÐÐÔ" ) command("say Ê¦Êå¼ûÐ¦ÁË¡£\n");
			else command("say Ê¦¹Ã¼ûÐ¦ÁË¡£\n");
		}
		else if( (int)ob->query("family/generation") ==3  )
		{
			command("kick " + ob->query("id") );
			command("say ÄãÕâ¸ö" + RANK_D->query_rude(ob) + "£¬¸ÒÀ´ÏûÇ²ÀÏ×Ó£¡\n");
		}
		else 
		{
			command("consider");
			command("say ÊÇÄã×Ô¼ºÒª°ÝµÄ£¬ÄãÊ¦¸¸´òÉÏÃÅÀ´ÎÒ¿ÉµÃÄÃÄãµ²¡£\n");
			command("recruit " + ob->query("id") );
		}
	}

	else
	{
		command("say ºÃ£¬ÎÒÎå×¯¹ÛÒ»ÃÅÈË²Å±²³ö£¬Äã¿ÉµÃ¸øÊ¦¸¸ÕùÆø¡£\n");
		command("recruit " + ob->query("id") );
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xian");
}




ÿ