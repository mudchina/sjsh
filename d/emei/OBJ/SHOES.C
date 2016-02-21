// shoes.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;


void create()
{
        set_name(HIW "¶ëáÒÏÉÂÄ" NOR, ({ "shoes" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "Ò»Ë«¶ëáÒÉ½µÜ×Ó´©µÄĞ¬¡£  \n");
		set("material", "cloth");
		set("unit", "Ë«");
                set("value", 30000);
                set("armor_prop/armor", 50 );
                set("female_only", 10);
                set("armor_prop/dodge", 20 );
        }
	setup();
}
//int query_autoload() { return 1; }

