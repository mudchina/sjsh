#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void init()
{
        add_action("do_aim","aim");
        add_action("do_shoot","shoot");
}

void create()
{
       set_name("AK47-冲锋枪", ({ "chongfeng qiang", "qiang", "gun" }) );
       set_weight(2000);
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("unit", "柄");
               set("bullet", 200);
               set("value", 50000);
               set("no_get", 1);
               set("no_give", 1);
               set("material", "steel");
               set("long", "这是一柄杀伤力极大的AK47冲锋枪，是世界性恐怖集团常用的致命武器。\n");
               set("wield_msg", "$N把一柄$n握在手中。\n");
               set("unequip_msg", "$N将手中的$n背到肩上。\n");
       }
       init_blade(100);
       setup();
}

int do_aim(string arg)
{
       object me, obj;

       if(arg=="swl") return 1;
       
       me = this_player();

       if( !arg )
               return notify_fail("你想杀谁？\n");

       if( this_object()->query("bullet") <=0)
               return notify_fail("子弹已经打光了。\n");

       if(!objectp(obj = present(arg, environment(me))))
               return notify_fail("这里没有这个人。\n");

       if( !obj->is_character())
               return notify_fail("看清楚一点，那并不是活物。\n");

       if(obj == me)
               return notify_fail("用 suicide 指令会比较快:P。\n");

       message_vision(HIR "\n$N举起AK47-冲锋枪，朝向$n的方向，脸上露出一丝诡异的笑容。\n\n" NOR, 
                       me, obj);

       set_temp("target", arg);

       return 1;
}

int do_shoot()
{
       object me, obj;
       string arg;

       me = this_player();

       if( !(arg = this_object()->query_temp("target")) ) 
               return notify_fail("你还没有瞄准你的射击目标！\n");

       if( !objectp(obj = present(arg, environment(me)) ))
               return notify_fail("你要射击的对象已经离开了。\n");

       message_vision(HIR "\n$N对准$n一阵狂扫！！！\n子弹象一片光芒地射向$n，$n片刻被射成两半！\n\n" NOR,
                       me, obj);

       this_object()->add("bullet", -20);
       obj->set_temp("last_damage_from", "被" + me->name() + "谋杀");
       obj->delete("env/immortal");
       obj->die();
       delete_temp("target");

       return 1;
}
