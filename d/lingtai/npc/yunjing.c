// worker.c

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("ÔÆ¾²", ({"yun jing", "yun"}));
        set("gender", "ÄÐÐÔ" );
        set("age", 33);
        set("long", "·½´çÉ½ÈýÐÇ¶´µÚÈý´úµÜ×ÓÖÐµÄ½Ü³öÈËÎï£®\n");
        set("combat_exp", 70000);
	set("daoxing", 100000);

        set("attitude", "peaceful");
	set("int", 25);
	set("class", "taoist");
        create_family("·½´çÉ½ÈýÐÇ¶´", 3, "µÜ×Ó");
	
        set("eff_dx", 30000);
        set("nkgain", 200);

        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("spells", 40);  
        set_skill("dao", 40);
        set_skill("literate", 40);
        set_skill("stick", 40);  
        set_skill("qianjun-bang", 40);
        set_skill("puti-zhi", 40);  
        set_skill("jindouyun", 40);
        set_skill("dodge", 40);  
        set_skill("force", 40);   
        set_skill("wuxiangforce", 40);

        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");


        set("per", 30);
        set("max_kee", 500);
        set("max_gin", 500);
        set("max_sen", 500);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 10);
        set("mana", 450);
        set("max_mana", 300);
        set("mana_factor", 5);

        setup();
	carry_object("/d/lingtai/obj/daoguanq")->wear();
        carry_object("/d/lingtai/obj/cloth")->wear();
        carry_object("/d/lingtai/obj/bang")->wield();
}
void attempt_apprentice(object ob, object me)
{
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) +
"¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓÐ³É¡£\n");
        command("recruit " + ob->query("id") );
	return;
}		

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
}

ÿ
