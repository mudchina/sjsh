// 干将剑 by Calvin 

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIW"干将剑"NOR, ({ "ganjiang sword", "ganjiang","jian", "sword" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 10000);
                set("material", "steel");
                set("no_sell",1);
                set("long", "这是一把天地间自然形成的一把纯白色宝剑，剑身透亮,锋利无比。\n");
                set("wield_msg", "一道白光闪过，$N手中已多了把$n。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_sword(80);
        setup();
}
