#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
          set_name( HIC "»˝ΩÁ…Ò√±°" NOR , ({ "sheng mao", "mao", "hat" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "∂•");
                set("long", "“ª∂•ŒÂ≤ ”Ò ØœÛ—¿”Òπ⁄°£\n");
                set("material", "steel");
                set("value", 4000);
                set("no_sell", 1);
                set("armor_prop/armor", 20);
                set("armor_prop/intelligence", 10);
                set("armor_prop/personality", 1);
        }
        setup();
}
