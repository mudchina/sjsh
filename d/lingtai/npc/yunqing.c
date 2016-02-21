// worker.c

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("ÔÆÇå", ({"yun qing", "yun"}));
        set("gender", "ÄÐÐÔ" );
        set("age", 33);
        set("long",
"·½´çÉ½ÈýÐÇ¶´µÚÈý´úµÜ×ÓÖÐµÄ½Ü³öÈËÎï£®\nËä²»ÊÇºÜ´ÏÃ÷£¬µ«Ê¦×æÈ´ºÜ¿´ÖØËû£®\n");
	set("int", 25);
	set("class", "taoist");
        set("combat_exp", 80000);
	set("daoxing", 100000);

        set("attitude", "peaceful");
        create_family("·½´çÉ½ÈýÐÇ¶´", 3, "µÜ×Ó");

        set("eff_dx", 30000);
        set("nkgain", 200);

        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("spells", 50);  
        set_skill("dao", 50);
        set_skill("literate", 30);
        set_skill("stick", 50);  
        set_skill("qianjun-bang", 50);
        set_skill("puti-zhi", 50);  
        set_skill("jindouyun", 50);
        set_skill("dodge", 50);  
        set_skill("force", 50);   
        set_skill("wuxiangforce", 50);

        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");

	set("str", 30);
        set("per", 30);
        set("max_kee", 400);
        set("max_gin", 400);
        set("max_sen", 400);
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
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
}

ÿ
