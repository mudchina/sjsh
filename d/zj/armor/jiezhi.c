// yinyangring.c “ı—ÙΩ‰÷∏

#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
        set_name(HIC"“ı—ÙΩ‰÷∏"NOR, ({ "yinyang jiezhi", "jiezhi", "ring" }));
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "÷ª");
                set("value", 0);
                set("material", "gold");
                set("armor_prop/armor", 35);
        }
        setup();
}       
