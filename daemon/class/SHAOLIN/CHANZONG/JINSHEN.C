#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void remove_effect(object me, int amount);
int cast(object me, object target)
{
        int skill;
   if( target != me ) return 
    notify_fail("你只能将"HIY"「金身护体」"NOR"用在自己的身上。\n");
        if( (int)me->query("mana") < 2*(int)me->query_skill("chanzong"))
        return notify_fail("你的法力不够了！无法施展"HIY"「金身护体」"NOR"！\n");
        if( (int)me->query_temp("daoqian") ) 
        return notify_fail("你已经在运功中了。\n");
        if( (int)me->query("sen") < 150 )
        return notify_fail("你的精神无法集中！无法施展"HIY"「金身护体」"NOR"！\n");
        skill = (int) me->query_skill("chanzong",1);
        if(skill < 100) return notify_fail("你的禅宗佛法等级不够。\n");
        skill = random(skill)+skill;
        me->add("mana", -150);
        message_vision( HIY"\n$N微微念起禅宗佛法，身上金光闪闪，渐渐现出金身。\n" NOR, me);
        me->add_temp("apply/dodge", skill);
        me->set_temp("daoqian", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me,skill :), skill);
        if( me->is_fighting() ) me->start_busy(2);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("daoqian");
   message_vision(HIY"$N身上的金光渐渐散去了。\n"NOR,me);
}
