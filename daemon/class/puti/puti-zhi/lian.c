//lian.c by peaceful

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「赤尻连拳」？\n");

        if(!me->is_fighting())
                return notify_fail("「赤尻连拳」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("force") < 300 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 200 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("puti-zhi", 1) < 100)
                return notify_fail("你的猴拳还不够纯熟，难以连续攻击！\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");

message_vision(HIY"\n$N吱哇乱叫了几声，忽然加快节奏，一连打出几拳！\n"NOR,me,target);

        me->set_temp("TP_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("TP_perform", 7);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        if (random(2))
              {
              me->set_temp("TP_perform", 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
              }

        me->delete_temp("TP_perform");

        me->receive_damage("sen", 50);
        me->add("force", -150);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(3);
        return 1;
}
