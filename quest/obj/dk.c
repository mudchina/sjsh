// pao.c
#include <ansi.h>
inherit EQUIP;

void create()
{
     set_name(HIY"ÃÔÄãÐ¡¶Ì¿ã"NOR, ({"dk", "pao", "cloth"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/armor", 100);
                set("armor_prop/dodge", 50);
                set("armor_prop/spells", 100);
             }
}
