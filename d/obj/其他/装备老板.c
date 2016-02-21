//inherit NPC;


inherit F_VENDOR_SALE;

void create()
{
//    reload("xiaoxue");
        set_name("萧雪", ({"xiao xue", "xiao"}));
        set("title", "千斤娘子");
        set("gender", "女性");
        set("age", 26);
        set("long", "老英雄萧振远的二女儿，千奇店女老板。
是“恶娘子”萧萧的二姐。\n");

        set("combat_exp", 70000);
        set_skill("fonxansword", 30);
        set_skill("sword", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("moondance", 50);
        map_skill("dodge", "moondance");
        map_skill("sword", "fonxansword");
        map_skill("parry", "fonxansword");
        set("force", 200);
        set("max_force", 200);
        set("force_factor", 5);

        set("vendor_goods", ([
//                "whip":    "/d/obj/stey/yaowhip1.c",
//                "hammer":    "/d/obj/stey/tianhammer.c",
//                "sword":    "/d/obj/stey/sttt.c",
//                "fork":    "/d/obj/stey/shenfork.c",
//                "spear":    "/d/obj/stey/shenspear.c",
//                "stick":    "/d/obj/stey/tianbang.c",
//                "mace":    "/d/obj/stey/goldjian.c",
//                "qin":    "/d/obj/stey/moqin.c",
//                "blade":    "/d/obj/stey/guiblade.c",
//                "staff":    "/d/obj/stey/shenstaff.c", 
                "spellsbook":    "/d/obj/book/mihou-book.c",   
                "parrybook":    "/d/obj/book/parrybook2",
                "forcebook":    "/d/obj/book/forcebook2",
        ]) );

        setup();
        carry_object("/d/obj/cloth/pink_cloth")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",1, ob);
        }
        add_action("do_vendor_list", "list");
        add_action("do_bid", "bid");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( name()+"一直含情脉脉地看着你。\n");
                        break;
        }
}
int accept_fight(object me)
{
        command("say 要玩一边去！\n");
        return 1;
}
int do_bid(string arg)                                                       
{
        object who = this_player();                                           
        object me = this_object();                                            
        if(!arg || present(arg,environment(me))!=me) return 0;                
           command("hammer "+who->query("id"));
                return 1;
}
