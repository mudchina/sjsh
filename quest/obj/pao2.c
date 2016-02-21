// pao.c
#include <ansi.h>
inherit EQUIP;

void create()
{
        set_name(HIR"´óºì°×º×ç­ç¯ÒÂ"NOR, ({"dao pao", "pao", "cloth"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/armor", 20);
                set("armor_prop/dodge", 20);
                set("armor_prop/spells",20);
             }
}
