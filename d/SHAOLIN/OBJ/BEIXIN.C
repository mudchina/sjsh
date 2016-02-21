// icy_cloth.c

#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name(BLK"Ìú±³ÐÄ"NOR, ({ "tie beixin", "beixin" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("value", 0);
		set("material", "cloth");
                set("armor_prop/armor", 150);
		set("shaolin",1);
	}
	setup();
}
