// leiyan.c   雷炎剑    created 20-08-2001 海上飘(piao)


#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIM"峨嵋剑"NOR, ({ "emei sword", "jian", "sword" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","这是一把峨嵋弟子的长剑。\n");
                set("value", 2400);
                set("material", "blacksteel");
                set("wield_msg", "$N从剑鞘中抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入剑鞘。\n");
        }
        init_sword(100);
        setup();
}
 
