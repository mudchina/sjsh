//cast escape.c 可用于各种逃遁。
//this one is for emei...piao, 

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	target = offensive_target(me);

	if( (int)me->query("mana") < 100 )
		return notify_fail("你的法力不够了！\n");

	if( (int)me->query("sen") < (int)me->query("max_sen")/2 )
                return notify_fail("你现在头脑不清醒，无法呼唤白眉救你！\n");

        if( (string)me->query("family/family_name") != "峨嵋派" )
                return notify_fail("你并非峨嵋派弟子，白眉不会来救你。\n");

        if( (int)me->query_skill("mahayana",1) < 80 )
                return notify_fail("你的大乘涅磐功不够纯熟，无法呼唤白眉救你！\n");

        if (environment(me)->query("no_flee"))
                return notify_fail("白眉无法驾到这里救你! \n");

        message_vision(HIW "$N一声长鸣仰天大叫：师尊救我！\n" NOR, me);
        message_vision(HIW "只见白眉从天上踏着祥云走了出来！\n\n" NOR, me);

	if(me->is_fighting() ) {
		if(random((int)me->query("max_mana")) > (int)target->query("max_mana")/2 && random((int)me->query("mana")) > (int)target->query("mana")/2 ) {
 message_vision(HIW "白眉纵身飞下抓住$N，白光一闪，顿时冲上云霄，无影无踪了！\n" NOR, me);
			me->receive_damage("sen", 50);
			me->add("mana", -100);
                        if(random(3)==0) me->move("/d/emei/jinding");
                        else if(random(3)==1) me->move("/d/emei/duguangtai");
                        else me->move("/d/emei/dgtsheshenya");
			message_vision(HIC "只听趴！地一声，$N从半空中掉下来，跌了个屁股开花！\n" NOR, me);
		}
		else{
 message_vision(HIC "白眉纵身飞下，却被$n法力逼住，冲不入战团。只好对着$N长唳一声，折了回去！\n" NOR, me, target);
			me->receive_damage("sen", 50);
			me->add("mana", -100);
		}
	}

	else{
message_vision(HIW "白眉纵身飞下抓住$N，白光一闪，顿时冲上云霄，一不小心$N跌了个七荤八素！\n" NOR, me);
		me->add("mana", -100);
	}

	return 3+random(5);
}

