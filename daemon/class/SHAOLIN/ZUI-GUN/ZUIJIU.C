// zuijiu.c 八仙醉酒

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
        int skill;
        if( !target ) target = offensive_target(me);
         if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「"HIB"八仙醉酒"NOR"」只能对战斗中的对手使用。\n");


        
                if( !target->query_temp("zui_baxian") )
               target->set_temp("zui_baxian", 1);
                skill = (int)me->query_skill("zuibaxian") / 15;

        if (me->query_skill_mapped("dodge") != "shaolin-shenfa")
                return notify_fail("你现在没有少林的身法，无法施展「"HIB"八仙醉酒"NOR"」。\n");
        if( (int)me->query_skill("shaolin-shenfa", 1) < 100 )
                return notify_fail("你的少林身法不够娴熟，使不出「"HIB"八仙醉酒"NOR"」！\n");
        if( (int)me->query_skill("yijinjing", 1) < 100 )
                return notify_fail("你的易筋经神功不够娴熟，使不出「"HIB"八仙醉酒"NOR"」！\n");
        if( (int)me->query("force", 1) < 300 )
                return notify_fail("你现在内力不足！\n");     

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
        
        message_vision(
    HIB "只见$N喷出一口酒气，一式"HIW"「八仙醉酒」"NOR""HIB"，围着$n"HIB"一摇一摆地走动着。"NOR"\n" NOR, me, target);

        me->start_busy(random(1));
        me->add("force", -200);
        me->add("sen", -10);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                 message_vision(
    HIR " $N脚下却是暗含八卦，步步紧逼，使得$n"HIR"不知所措！"NOR"\n" NOR, me, target);
                target->start_busy( skill/50 + 3);
        } 
        else if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                 message_vision(
    HIR " 却见$N脚下暗含八卦，步步紧逼，使得$n"HIR"跌倒在地难以出招！"NOR"\n" NOR, me, target);
                target->start_busy( skill/50 + 5);
        }
        else {
          message_vision(
    CYN "可是$n"CYN"看破了$N的招数，向后纵了开去。"NOR"\n" NOR, me, target);
          me->start_busy(2);
        }
        target->add_temp("zui_baxian", 1);
        return 1;
}
