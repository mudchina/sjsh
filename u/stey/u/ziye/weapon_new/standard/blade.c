// blade.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("�ֵ�", ({"gang dao", "gangdao", "dao", "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "iron");
              set("keenness", 10);
		set("long", "����һѰ���ĵ�����������Լ�����߽��ء�\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
	}
	init_blade(25);
	setup();
}