// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// yahuan1.c

inherit NPC;

void create()
{
       set_name("丫环", ({"yahuan"}));
       set("long","一个小丫环，正和水母娘娘下棋。\n");
       set("gender", "女性");
       set("age", 16);
       set("attitude", "friendly");
       set("shen_type", 1);
   set("combat_exp", 500);
   setup();
        carry_object("/d/obj/cloth/skirt")->wear();
}

