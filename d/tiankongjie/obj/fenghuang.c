// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// jiasha.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
inherit F_UNIQUE;

void init()
{
  cloth::init();
  unique::init();
}

void create()
{
   set_name(HIR"�����--���"NOR, ({ "shen jiazhou", "jiazhou" }) );
   set("long", "������¥�������ӵ��������ף�����һ����\n");
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("material", "cloth");
     set("armor_prop/armor", 90);
     set("armor_prop/spells", 50);
     set("armor_prop/dodge", 80);
     set("replace_file", "/d/obj/cloth/hufa-jiasha");
                set("value", 50000);
   }
   setup();
}