// blade.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("Âà´¸", ({"luochui", "hammer"}));
        set_weight(200);
              set("keenness", 0);
                       set("material", "iron");

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
        }
        init_hammer(1);
        setup();
}

