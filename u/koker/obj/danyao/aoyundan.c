// 《仙侣情缘*三界神话》

// aoyundan.c 奥运大补丸
// koker  13/07/2001

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
        if (!wizardp(this_player())) {
                set("no_get", "嘿嘿，做梦吧! \n");
                set("no_sell", "嘿嘿，做梦吧! \n");
                set("no_give", "嘿嘿，做梦吧! \n");
                set("no_drop","这么珍贵的机会，哪能舍弃？! \n");
        }
        add_action("do_eat", "eat");
}

void create()
{
  set_name(YEL "奥运大补丸" NOR, ({"aoyun wan","wan","aoyun","dan"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
   else {
     set("unit", "颗");
     set("long", "北京奥运申办成功庆贺大补丸。上面刻有：“新北京，新奥运”六个字。\n");
     set("drug_type", "补品");
        }
  set("is_monitored",1); //监控精灵
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  
  if (!id(arg)) 
    {
      return notify_fail("你要吃什么？\n");
    }
       else
         {
           me->set("food", (int)me->max_food_capacity());
           me->add("potential",150000);
           message_vision(HIC "$N吃下一颗奥运大补丸，只觉体内冉冉升起一道道爱国的激流，激动之余你还没忘了对着世界大喊道：祖国我爱你！我的心永远属于你！祖国万岁，奥运万岁！ \n" NOR, me);
           destruct(this_object());  //毁灭这个物品
           return 1;
         }
 }


