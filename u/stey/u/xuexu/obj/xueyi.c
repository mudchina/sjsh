// created 19/3/2001 by xuexu
#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
set_name(HIW"雪蝉长衫"NOR, ({"xueyi", "cloth"}) );
set("long", "当年天神帝悉以雪峰绝顶的雪蝉所做成的衣服，据说穿了可以登入天神之殿。n");
set_weight(0);
set("wear_msg", HIW"$N微微一笑，将雪蝉长衫披上了全身，再以面纱蒙上面目，只留下一层诡异的朦胧。\n"NOR);
set("unequip_msg",HIW"$N伸手将脸上的面纱摘了下来，一股带着寒意的美弥漫了整个空间。\n"NOR);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "件");
set("material", "cloth");
set("armor_prop/per", 100);
set("armor_prop/dodge", 200);
set("armor_prop/armor", 100);
set("value", 0);
set("female_only", 1);
}
setup();
}
