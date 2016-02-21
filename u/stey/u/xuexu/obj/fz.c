#include <ansi.h>

inherit ITEM;

void create()
{
set_name( HIC "飞机" NOR , ({"feiji"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "只");
    set("value", 0);
  }
  setup();
}
void init()
{
  add_action("do_fang", "fang");
}

int do_fang(string arg)
{
  object me = this_player();
  object ob;

  message_vision ("$N一扬手中的飞机，飞机在风中飞了起来。\n",me,ob);
  call_out("fly",5,ob);  
  return 1;
}
void fly (object ob)
{
  object me = this_player();
  message_vision (HIC"飞机在风中飞着。\n" NOR,me,ob);
}

