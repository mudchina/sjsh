#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
        set_name(CYN "Í­ÅÆ" NOR, ({ "tongpai", "pai" }));
        set("long", @LONG
ÕâÊÇÒ»¿éºÚ÷î÷îµÄÍ­ÅÆ£¬ÉÏÃæĞ´×Å¡°Íõ¸®ÁîÅÆ¡±ËÄ¸öĞ¡×Ö¡££
LONG);
        set("weight", 100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "¿é");
                set("value", 0);
                set("material", "Í­");
                set("armor_prop/armor", 1);
        }
        setup();
}

