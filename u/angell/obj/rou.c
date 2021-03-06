#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
      if(this_player()==environment())
        add_action("do_eat", "eat");
}

void create()
{
        set_name(BLINK "唐僧肉" NOR, ({"tangseng rou", "tangseng rou", "rou"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "块");
              set("no_sell",1);
                        set("no_drop",1);
                         set("no_give",1);
                set("drug_type", "补品");
        }
  
        set("is_monitored",1);
        setup();
}

int do_eat(string arg)
{
        int howmany;

        object me = this_player();
  
        if (!id(arg)) return notify_fail("你要吃什么？\n");

        howmany = (int)me->query("rsg_eaten");
  
        me->set("food", (int)me->max_food_capacity());

        me->set("rsg_eaten", howmany+5);

        message_vision(HIW "$N把唐僧肉往嘴里一塞，大嚼特嚼了起来。\n" NOR, me);  

        me->set("obstacle/wuzhuang","done");
            me->add("cps",-1);

        //for live forever...
        if( me->query("rsg_eaten") >= 36 )
        {
                me->announce_live_forever( me->query("name")+"因吃下了唐僧肉，终于修成了不堕轮回，从此跳出三界外，不在五行中，永无生死大限了！" );
        }

        destruct(this_object());

        return 1;
}
