// piao
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("piaoxiang",1);
	if ( extra < 100) return notify_fail("��ģ�"HIR"Ѫ��Ʈ��"NOR"�ݻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��"HIR"Ѫ��Ʈ��"NOR"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
	message_vision(HIR"$N��̤�˷���������Ѫ��֮��Ʈ��һ˿Ѫ�ȣ�Ʈ�첻����\n"NOR,me,target);
	if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
	{
	message_vision(HIW"���$N���ŵ��ۻ����ң���Ӧ��Ͼ��\n"NOR,target);
	target->start_busy(3);
	}
	else{
	msg = ""HIW"��ϧ$N������$n������������ѸȻ������"NOR"";
	COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);	
	}
	return 1;
}