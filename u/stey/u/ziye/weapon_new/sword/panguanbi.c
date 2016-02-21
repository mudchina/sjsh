// blade.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("ÅÐ¹Ù±Ê", ({"panguanbi", "sword"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
              set("keenness", 0);
                set("value", 300);
                        set ("material", iron);
        }
        init_sword(20);
        setup();
}
