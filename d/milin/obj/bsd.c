// bianshi dan.c 变尸丹

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;
int do_drink(string);
void init();

void init()
{
    if(this_player()==environment())
add_action("do_eat", "eat");
}
void create()
{
set_name(MAG"变尸丹"NOR, ({"bianshi dan","dan"}));
set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
  set("long", "这是无天老魔潜心炼就的怪药,多食无益。\n");
set("unit", "颗");
 set("value", 0);
        }
}
int do_eat(string arg)
{
  object me = this_player();
if (arg!="dan") return 0;
me->set("eff_sen", (int)me->query("max_sen"));
me->set("eff_kee", (int)me->query("max_kee"));
me->set("eff_sen", (int)me->query("sen"));
me->set("eff_kee", (int)me->query("kee"));
me->set("mana", (int)me->query("max_mana"));
me->set("force", (int)me->query("max_force"));
me->set("mana", (int)me->query("mana"));
me->set("force", (int)me->query("force"));
me->set("bellicosity", (int)me->query_kar()*2);
me->add("daoxing",1000+random(1000));
message_vision("$N吃下了一颗变尸丹,时间久了可能会引变为腐尸。\n", me);
  destruct(this_object());
  return 1;
}
