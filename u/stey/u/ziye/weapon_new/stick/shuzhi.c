//add keenness by ziye 2001/3

#include <weapon.h>

inherit STICK;

void create()
{
        set_name("Ê÷Ö¦", ({"shuzhi"}));
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸ù");
                set("material", "wood");
              set("keenness", 0);
        }
        init_stick(8);
        setup();
}

