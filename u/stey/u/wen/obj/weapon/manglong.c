//manglong.c
//weiwei
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("莽龙锤", ({ "hammer" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把由莽龙所化之锤，重千斤，兀自闪烁不定。\n");
                set("value", 500000);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，大喝一声，顿时龙形闪烁，霞光万丈。\n");
                set("unwield_msg", "$N放下手中的$n，霞光顿收于$n。\n");
        }
        init_hammer(105);
        setup();
}

