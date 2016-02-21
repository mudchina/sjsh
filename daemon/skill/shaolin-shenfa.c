// shaolin-shenfa.c
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
	"$n������������ˮ��,ǰ��Žż�Ÿ��࿿��һʽ��һέ�ɽ����������ࡣ\n",
"����$n����Ʈ��������һ�ݣ����ѱܿ���\n",
	"$n˫��ǰ�죬ȫ������ƽ��,һʽ�������Ӳ�����ʱ������$N���������ơ�\n",
"$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
	"$nһ�����ã�һʽ���Ʋ����Ρ����㲻�����ֲ�̧��һת�ۼ���Ƶ���$N������\n",
"����$n����һ�ã�$N��һ�����˸��ա�\n",
	"$n����һ�㣬һʽ��������Ӱ����һת���䣬����˷�Ʈ����������$n����Ӱ,$N������롣\n",
"ȴ��$n�㲻��أ����Դܿ����ߣ����˿�ȥ��\n",
           "����$nһʽ���������ա���ȫ����ֱ���εض����ڰ����һת�����䵽����Զ�ĵط���\n",
"$n����΢�Σ��о����յرܿ���$N��һ�С�\n"
	"����$n�ظ�����һ��,�������������������ݷ�����һʽ������˫�ɡ�����$Nͷ����Ծ������\n",
"����$nǡ����������һ���������$N��һ�С�\n",
	"$n���˼���,һʽ��������ˮ����˫�ŵ�أ�ȫ����Ϊһ����Ӱ����������$N���˼�ת��\n",
 "$n�������ĵ���������һ�����պñܹ�$N���������ơ�\n",
       "ֻ��$n���������ݰ㼱ת�������γ�һ��������,һʽ���ɷ�鳲���$N������䣬�������á�\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 0 )
		return notify_fail("�������������û�а취������������\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("���������������������������������\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
