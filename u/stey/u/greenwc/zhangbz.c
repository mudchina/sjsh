inherit NPC;

void create()
{
           set_name("张柏芝", ({"zhang bai zhi","zhang", "zhi"}));
set("long","红的发紫的大明星，不过现在是雨点的私人秘书了．\n");
       set("gender", "女性");
set("title","雨点的私人助理");
       set("age", 24);
        set("per", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
        set_skill("dodge", 200);
        set_skill("moondance", 200);
        set_skill("sword", 200);
        set_skill("snowsword", 200);
        map_skill("dodge", "moondance");
        map_skill("sword", "snowsword");
        set("force", 3000);
        set("max_force", 3000);
        set("force_factor", 50);
        set("combat_exp", 1200000);
  set("daoxing", 5000000);
        set("max_mana", 3000);
        set("mana", 3000);
        set("mana_factor", 50);
        setup();
        add_money("gold", 5);
}
