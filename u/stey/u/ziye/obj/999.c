// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;


void create ()
{
  set_name(HIB "�Űپ�ʮ�Ŷ�õ��" NOR, ({ "flower"}));
  set_weight(100);
  set("long","ɫ��������"+query("name")+"��\n");
  set("unit", "��");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 2);
  set("unequip_msg","$N��"+query("name")+"�����ժ����������\n");
  set("wear_msg", "$N����"+query("name")+"��������������ʱ�����������ˡ�\n");
  setup();
}

