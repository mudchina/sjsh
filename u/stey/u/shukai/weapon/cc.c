#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
       set_name(HIR "太极道袍" NOR, ({"cloth", "pao"}));
        set_weight(2000);
		set("long",
"一件道士穿的长袍，中有太极八卦，左右绣有日月乾坤．\n");
                set("unit", "件");
                set("value", 500);
                set("material", "cloth");
                set("armor_prop/armor_vs_force", 400);
                set("armor_prop/spells", 5);
             }

