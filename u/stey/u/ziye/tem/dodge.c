// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
       string msg;
       int extra,add_dodge;
       string *mapped;
       mapping map;
       if ( me->query("sen")<30 )
            return notify_fail(RED"你元神不济,强行运功会害了自己!\n"NOR);
       if ( me->query("force")<100 )
            return notify_fail(RED"你内力不够，强行运功会害了自己!\n"NOR);
        extra = me->query_skill("xiake-bufa",1);
        if (extra < 30) return notify_fail(RED"你的〖侠客步法〗还不够纯熟！\n"NOR);
       map = me->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});
        if( member_array("xiake-shengong",mapped)==-1 )
                return notify_fail(HIR+"你现在使用的轻功与【侠客步法】相抵触，不能施展〖流星蝴蝶步〗。\n"+NOR);
        if( member_array("xiake-shengong",mapped)==-1 )
                return notify_fail(HIR+"你必须运用侠客神功与侠客步法配合，才能施展〖流星蝴蝶步〗。\n"+NOR);
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIR"〖流星蝴蝶步〗"+NOR+"只能对战斗中的对手使用。\n"+NOR);
       if( me->query_skill("xiake-bufa",1)<100 )
         {
                if(target->is_busy())
                        return notify_fail(target->name()+"已经手忙脚乱了！\n");
                message_vision(HIY"\n$N脚踩连环，环绕着$n飞速转了起来！\n\n"+NOR,me,target);
                if(random((int)target->query("combat_exp")/3) < (int)me->query("combat_exp"))
                {
                        message_vision(HIR"只见"+target->query("name")+"四周就象有千万只"HIY"蝴"HIC"蝶"HIM"在"HIG"飞"HIB"舞"HIY",\n
                              结果$N被扰得眼花潦乱，接应不暇！手脚顿时慢了下来.\n"NOR,target);
                        target->start_busy(2);
        if((me->query("family/family_name")!="侠客岛"))
        {    me->start_busy(random(3));   return 1;   }
                }
                else
                {
                        message_vision(HIY"结果$N自己转了个头晕眼花！手脚顿时慢了下来.\n"+NOR,me);
                        me->start_busy(3);
                  }
         }
      if( (me->query_skill("xiake-bufa",1)<300)&&(me->query_skill("xiake-bufa",1)>100) )            
         {
                if(target->is_busy())
                        return notify_fail(target->name()+"已经手忙脚乱了！\n");
                message_vision(HIY"\n$N脚踩连环，环绕着$n飞速转了起来！\n\n"+NOR,me,target);
                if(random((int)target->query("combat_exp")/2) < (int)me->query("combat_exp"))
                {
                        message_vision(HIR"只见"+target->query("name")+"四周就象有千万只"HIY"蝴"HIC"蝶"HIM"在"HIG"飞"HIB"舞"HIY",\n
                              结果$N被扰得眼花潦乱，接应不暇！手脚顿时慢了下来..\n"NOR,target);
        if((me->query("family/family_name")!="侠客岛"))
        {    me->start_busy(random(3));   return 1;   }
                        me->start_busy(3);
                }
                else
                {
                        message_vision(HIY"结果$N自己转了个头晕眼花！手脚顿时慢了下来..\n"+NOR,me);
                        me->start_busy(3);
               }
                 }
          if( me->query_skill("xiake-bufa",1)>300 )            
         {
                if(target->is_busy())
                        return notify_fail(target->name()+"已经手忙脚乱了！\n");
                message_vision(HIY"\n$N脚踩连环，环绕着$n飞速转了起来！\n\n"+NOR,me,target);
                if(random((int)target->query("combat_exp")*7/10) < (int)me->query("combat_exp"))
                {
                        message_vision(HIR"只见"+target->query("name")+"四周就象有千万只"HIY"蝴"HIC"蝶"HIM"在"HIG"飞"HIB"舞"HIY",\n
                              结果$N被扰得眼花潦乱，接应不暇！手脚顿时慢了下来...\n"NOR,target);

                        target->start_busy(4);
        if((me->query("family/family_name")!="侠客岛"))
        {    me->start_busy(random(4));   return 1;   }
                }
                else
                {
                        message_vision(HIY"结果$N自己转了个头晕眼花！手脚顿时慢了下来...\n"+NOR,me);
                        me->start_busy(2);
               }
                 }
       me->receive_damage("sen", 50);
       me->add("force", -100);
        return 1;
}


