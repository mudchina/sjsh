// 逆仞劍.c


#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
  set_name(HIC  "逆仞劍" NOR, ({ "niren sword", "jian", "sword" }) );
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "杆");
    set("value", 10000);
    set("material", "blacksteel");
    set("long", "獨一無二的逆仞劍,它鋒利無比,它是緋村劍心的兵器。\n");
    set("wield_msg", "一道寒光闪过，$N手中已多了把$n。\n");
       set("unequip_msg", "$N放下手中的$n。\n");
  }
  init_spear(490);
  setup();
}

