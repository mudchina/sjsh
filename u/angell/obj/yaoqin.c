// yaoqin.c

inherit YUEQI;

void create()
{
set_name("����", ({ "yao qin" }) );
set_weight(2000);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "��");
set("long", "����һ���������������١�\n");
set("value",1000);
set("material", "bamboo");
}
setup();
}
