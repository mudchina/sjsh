#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"ª¡È÷È"NOR, ({ "huo lingzhu" }));
        set_weight(20000);
        set("long", "’‚ «“ªø≈±¶÷È°£\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ø≈");
                set("material", "stone");
                set("value", 2000);
                set("no_get", 1);
                set("amount",30);
        }
        setup();
}
