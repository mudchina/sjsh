#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
  set_name(HIC"พํิฦาย"NOR,({"juanyun yi","yi"}));
 set_weight(1000);
   if(clonep() )
    set_default_object(__FILE__);
   else {
    set("material","silk");
   set("unit","ผþ");
   set("value",10000);
    set("armor_prop/armor",100);
    set("armor_prop/dodge",100);
    set("armor_prop/parry",100);
}
  setup();
}
