//tianlei.c ����ɽ���ռ� ���׺�һ ����Ʈ(piao)
#include <ansi.h>
#include <combat.h> 
void tianlei_ok(object);
inherit SSERVER;
int perform(object me, object target)
{
              string str;
              object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�"HIW"���׺ϲ�"NOR"����\n");
        if(!me->is_fighting())
                return notify_fail("��"HIW"���׺ϲ�"NOR"��ֻ����ս����ʹ�ã�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
              return notify_fail(" ��ʹ�õ��������ԣ��޷�ʩչ��"HIW"���׺ϲ�"NOR"����\n");
        if (me->query_skill_mapped("force")!="emeiforce")
                return notify_fail("��"HIW"���׺ϲ�"NOR"��������϶����ķ�����ʹ�á�\n");
          if((int)me->query("force") < 1000 )
		  return notify_fail("����������㣡\n");
        if((int)me->query("max_force") < 3000 )
                return notify_fail("�������������\n");
        if((int)me->query("sen") < 1000 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query("combat_exp") < 1500000 )
                return notify_fail("����ѧ���鲻�������򲻵���"HIW"���׺ϲ�"NOR"����\n");
        if( me->query("force_factor") > 0)
                return notify_fail("��"HIW"���׺ϲ�"NOR"���������в������������������ܽ������飿\n");
        if((int)me->query_skill("emeiforce",1) < 180 )
                return notify_fail("��Ķ����ķ����𻹲�����ʹ������"HIW"���׺ϲ�"NOR"����\n");
        if((int)me->query_skill("zhutian-bu",1) < 180 )
                return notify_fail("������컯�������𻹲�����ʹ������"HIW"���׺ϲ�"NOR"����\n");
        if((int)me->query_skill("jinding-zhang",1) < 180 )
                return notify_fail("��Ľ����Ƽ��𻹲�����ʹ������"HIW"���׺ϲ�"NOR"����\n");
        if((int)me->query_skill("tianlei-sword", 1) < 180 )
                return notify_fail("�������˫����������ʹ����һ�л������ѣ�\n");
        if(me->query_temp("no_tianlei"))  //�ڴ˴����ñ�־λ ;
		return notify_fail("��ո�ʹ����"HIW"���׺ϲ�"NOR"��,��ЪһЪ�ɡ�\n");
        me->delete("env/brief_message");
	target->delete("env/brief_message");

message_vision(HIM "$N���ֻó�һ����⣬�������ὣ��"HIG"���ֻó�һ���̹⣬�������׽���\n"NOR,me,target);
message_vision(HIW"˫�ֻ���֮�佫�˶�����Ϊһ����˲�仯��һ���ʺ���������٣�����һ�С�"HIC"���׺ϲ�"HIW"����\n"NOR,me,target);
message_vision(HIC"$n��û�����ü����������ô���£��Ա��ʺ�͸�������\n" NOR,me,target);
        me->set_temp("QJB_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 2);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->set_temp("QJB_perform", 3);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->set_temp("QJB_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        if( (int)me->query_skill("tianlei-sword", 1) > 150 ) {
message_vision(HIR"��������\n"NOR,me,target);
message_vision(HIR"�� "HIY"��"HIR" ��\n"NOR,me,target);
message_vision(HIR"��������\n"NOR,me,target);
        me->set_temp("QJB_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
}
        if( (int)me->query_skill("tianlei-sword", 1) > 160 ) {
message_vision(HIR"          ��������\n"NOR,me,target);
message_vision(HIR"          �� "HIY"��"HIR" ��\n"NOR,me,target);
message_vision(HIR"          ��������\n"NOR,me,target);
        me->set_temp("QJB_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
}
        if( (int)me->query_skill("tianlei-sword", 1) > 170 ) {
message_vision(HIR"                    ��������\n"NOR,me,target);
message_vision(HIR"                    �� "HIY"��"HIR" ��\n"NOR,me,target);
message_vision(HIR"                    ��������\n"NOR,me,target);
        me->set_temp("QJB_perform", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
}
        if( (int)me->query_skill("tianlei-sword", 1) > 180 ) {
message_vision(HIR"                               ��������\n"NOR,me,target);
message_vision(HIR"                               �� "HIY"��"HIR" ��\n"NOR,me,target);
message_vision(HIR"                               ��������\n"NOR,me,target);
        me->set_temp("QJB_perform", 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
}
        if( (int)me->query_skill("tianlei-sword", 1) > 190 ) {
message_vision(HIR"                               ��������\n"NOR,me,target);
message_vision(HIR"                               �� "HIY"��"HIR" ��\n"NOR,me,target);
message_vision(HIR"                               ��������\n"NOR,me,target);
        me->set_temp("QJB_perform", 9);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
}
        if( (int)me->query_skill("tianlei-sword", 1) > 200 ) {
message_vision(HIR"                    ��������\n"NOR,me,target);
message_vision(HIR"                    �� "HIY"��"HIR" ��\n"NOR,me,target);
message_vision(HIR"                    ��������\n"NOR,me,target);
        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
}
        if( (int)me->query_skill("tianlei-sword", 1) > 210 ) {
message_vision(HIR"          ��������\n"NOR,me,target);
message_vision(HIR"          �� "HIY"��"HIR" ��\n"NOR,me,target);
message_vision(HIR"          ��������\n"NOR,me,target);
        me->set_temp("QJB_perform", 11);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
}
        if( (int)me->query_skill("tianlei-sword", 1) > 220 ) {
message_vision(HIR"��������\n"NOR,me,target);
message_vision(HIR"�� "HIY"��"HIR" ��\n"NOR,me,target);
message_vision(HIR"��������\n"NOR,me,target);
        me->set_temp("QJB_perform", 12);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
}
 if (target->query("eff_kee")<0 || !living(target))  
{str=target->name()+"��"+""HIW""+me->name()+""HIM""+"�ö���ɽ�ľ��С�"HIW"���׺ϲ�"HIM"��ɱ���ˡ���˵ʬ�屻�����ճ��˻ҽ���";
        message("channel:rumor",HIM"��"HIW"��Ѩ����"HIM"��ĳ�ˣ�"+str+"\n"NOR,users());
	               }
        me->delete_temp("QJB_perform");
        me->receive_damage("sen", 100);
        me->add("force", -1000);
        me->set_temp("no_tianlei",1); ;
        me->start_busy(3);
        call_out("tianlei_ok",20+random(10),me); ;
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        return 1;
}
void tianlei_ok(object me) 
{ if (!me) return; 
      me->delete_temp("no_tianlei"); 
}











