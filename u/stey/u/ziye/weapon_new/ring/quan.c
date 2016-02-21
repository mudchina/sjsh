// hammer.c
#include <ansi.h>
#include <weapon.h>

inherit UNARMED;

void create()
{
        set_name(HIW "铁拳" NOR, ({"tie quan", "quan"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long",
"拳师专用。\n");
                set("value", 5000);
                set("material", "diamond");
                set("wield_msg",
"$N戴上一个$n。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_unarmed(50);
        setup();
}

