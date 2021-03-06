// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_DBASE;

inherit SSERVER;

int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	int tmp;
	object weapon;
	extra = me->query_skill("bingpo-blade",1);
	if ( extra < 150) return notify_fail("你的［冰魄寒刀］还不够纯熟！\n");
               if(me->query("family/family_name")!="大雪山")
                return notify_fail("非雪山不能用「千蛇出洞」！\n");
	dodskill = (string) me->query_skill_mapped("dodge");
	if ( dodskill != "xiaoyaoyou")
			return notify_fail("［千蛇出洞］需要［逍遥游］的配和！\n");
	tmp = me->query_skill("xiaoyaoyou",1);
	if ( tmp < 150 )return notify_fail("你的［逍遥游］还不够纯熟！\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［千蛇出洞］只能对战斗中的对手使用。\n");
	me->add_temp("apply/attack",tmp);
	me->add_temp("apply/damage",extra);
	weapon = me->query_temp("weapon");
	message_vision( HIR  "\n\n$N手中的"+weapon->query("name")+"幻出千朵刀花使出冰魄寒刀的不传绝学 ---千-蛇-出-洞--- ！！\n\n\n青蛇欲探头！\n$N手中"+weapon->query("name")+"直刺$n！" NOR,me,target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision( HIY  "青蛇微吐芯！\n$N手中"+weapon->query("name")+"斜劈$n！" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision( HIG  "青蛇翻身搏！\n$N手中"+weapon->query("name")+"横劈$n！" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision( HIM  "青蛇啮八方！\n$N手中"+weapon->query("name")+"猛劈$n！" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision( HIC  "青蛇云里游！\n$N手中"+weapon->query("name")+"反撩$n！" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
          me->start_busy(2);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
	return 1;
}
