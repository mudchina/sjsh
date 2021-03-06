// sishi.c 天魔四蚀

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int qi_gain, qi_lost, ap, dp, success;
	string msg;	

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
	return notify_fail("你想摄取谁的阳气？\n");
    
	if( target == me ) return notify_fail("你疯了？\n");

	if(target->query_temp("netdead")) return notify_fail("趁火打劫，不太像话吧？\n");

	if( (int)me->query_skill("tianmogong", 1) < 40 )
		return notify_fail("你的「天魔功」修为太低，不能摄取阳气。\n");

	if( (string)me->query("class") != "sanjie" )
		return notify_fail("你并非三界山门人，不能摄取阳气。\n");

        if(!me->is_fighting()||!target->is_fighting())
                return notify_fail("只能在战斗中摄取阳气。\n");

	if( (int)me->query("kee")  > 3*(int)me->query("max_kee")/2 )
		return notify_fail("你现在气太过充盈，再吸就要爆炸了。\n");

	qi_lost = target->query("kee") / 5;

	if(qi_lost < 5 )
		return notify_fail("对方马上就要断气，没有什么好榨的了。\n");
	
	msg = HIR"\n$N面带狞笑，露出白森森的牙齿往$n"NOR+HIR"的鼻孔凑了过去，张嘴就是一吸！\n" NOR;

	success = 1;

	ap = me->query_skill("force");
	ap = ap * ap * ap /10 ;
	ap += (int)me->query("combat_exp");
	dp = target->query("combat_exp");
	if( random(ap)+ap/2 < random(dp)+dp/2 ) success = 0;

	ap = (int)me->query("max_mana");
	dp = (int)target->query("max_mana");
	if( random(ap*2) < dp ) success = 0;

	if(success == 1 ){
		msg +=  HIR "结果$n"NOR+HIR"头皮一麻，只觉得体内阳气源源不断地流了出去！\n" NOR;
		qi_lost=qi_lost-random(qi_lost/2);
		target->receive_damage("kee", qi_lost, me);

		qi_gain = qi_lost;
		if( (int)target->query("max_kee") < (int)me->query("max_kee") )
			qi_gain = qi_gain * (int)target->query("max_kee")/(1+(int)me->query("max_kee"));

		if( (int)target->query("combat_exp") < (int)me->query("combat_exp") )
			qi_gain = qi_gain * (int)target->query("combat_exp")/(1+(int)me->query("combat_exp"));

		if( qi_gain > 0 ) me->add("kee", qi_gain);

		if( qi_gain > 0 
		&& (int)me->query("combat_exp") < (int)target->query("combat_exp") 
		&& (int)me->query_skill("tianmogong",1) <= 200
		&& random(3) < 1 )
		{
			me->improve_skill("tianmogong", qi_gain);
		} else {
			if( qi_gain < 0 ) qi_gain =1;
			me->improve_skill("tianmogong", qi_gain, 1);
		}
	} else {
		msg +=  HIR "结果$n一扭头，避了开去！\n" NOR;	
	} 

	message_vision(msg, me, target);
	if( success == 1 ) COMBAT_D->report_status(target);

	if( living(target) ) target->kill_ob(me);

	me->start_busy(4);        
	return 1;
}
