// icy_boot.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name(HIW"��ѩ����ѥ"NOR , ({ "icy boots", "boots" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 8000);
		set("material", "cloth");
		set("armor_prop/armor", 8);
		set("armor_prop/dodge", 25);
	}
	setup();
}
