#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;
void create()
{
set_name(HIW "千年雪之露" NOR, ({ "xuelu"}));
set_weight(600);
if( clonep() )
set_default_object(__FILE__);
else {
set("long", "一杯由天山上刚采来的千年雪莲，配以埋在地下的百年菊花瓣，熬制成的清水寒冰露。\n");
set("unit", "杯");
set("value", 120);
set("max_liquid", 100); 
set("liquid_supply", 80);
};
set("liquid", ([
"type": "water",
"name": "千年雪之露",
"remaining": 90,
]) );
setup();
}
