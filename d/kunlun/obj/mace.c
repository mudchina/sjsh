//mace.c
//created 6-31-2001 by piao

#include <weapon.h>
#include <ansi.h>

inherit MACE;

void create()
{
  set_name(HIW"打神鞭"NOR, ({"dashen whip", "mace", "dashen","whip"}));
  set_weight(17000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "根");
    set("value", 1000);
    set("material", "iron");
    set("long", "一柄普通的竹节鞭。\n");
    set("wield_msg", "$N操起一根$n，摆了个架式。\n");
    set("unwield_msg", "$N将$n别回腰间。\n");
  }
  
  init_mace(150);
  setup();
}

