#include <ansi.h>
#include <armor.h>

inherit BOOTS;


void create()
{
        set_name(HIW"Ì©É½¶À½ÅÐ¬¡ª¡ªÓÒ"NOR,({ "right shoe", "xie","shoe" }) );
        set_weight(1000);
                set("unit", "Ö»");
                set("value", 0);
                set("material", "cloth");
        set("armor_prop/armor", 10 );
        set("armor_prop/dodge", 15 );
        setup();
}
