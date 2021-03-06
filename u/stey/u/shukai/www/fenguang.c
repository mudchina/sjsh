#include <ansi.h>
inherit SSERVER;
#include "/daemon/skill/eff_msg.h";

int perform(object me, object target)
{
        string msg;
        int damage, p,time;
        if( !target ) target = offensive_target(me);
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("「分光化影」只能在战斗中使用。\n");
        if( (int)me->query_skill("mindsword", 1) < 60 ||
           (int)me->query_skill("zixia-shengong", 1) < 100 )
                return notify_fail("你有的功夫还不够娴熟，不会使用「分光化影」。\n");
                if(me->query("family/family_name") != "蜀山剑派" )
                return notify_fail("你是哪儿偷学来的武功！\n");
        if( (int)me->query("max_force") < 600 )
                return notify_fail("你的内力修为太弱，不能使用「分光化影」！\n");
        if( (int)me->query("force") < 600 )
                return notify_fail("你的真气不够！\n");
        message_vision(HIW"\n$N如痴如狂，口中喃喃自语：\n",me,target);
        message_vision(HIW"\n挫其锐，解其纷，和其光，同其尘。\n",me,target);
       msg = HIW "\n     $N一剑斜斜刺来。\n\n" NOR;
            me->start_busy(1);
            target->start_busy(1);
if (random(me->query("combat_exp")) > random((target->query("combat_exp")/3)))
        {
                if(me->query_skill("mindsword", 1) > 299)
                   call_out("perform5", 1, me, target);    
                  else  if(me->query_skill("mindsword", 1) > 239)
                   call_out("perform4", 1, me, target);    
                  else  if(me->query_skill("mindsword", 1) > 179)
                   call_out("perform3", 1, me, target);    
                  else  if(me->query_skill("mindsword", 1) > 119)
                   call_out("perform2", 1, me, target);    
                else
                   call_out("perform1", 1, me, target);    
        } else 
        {       me->start_busy(3);
                me->add("force", -100);                
                msg += HIY"可是$p识得其诈，躲过了这一招。\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}
int perform1(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");
        if(!me->is_fighting(target)) 
          return notify_fail("战斗已经结束了。\n");
        msg = HIY "\n$p眼见$N露出破绽，急忙主动出击\n" NOR;
        message_vision(msg, me, target); 
       msg = HIC "谁知$N这招却是虚招，$p发现时为时已晚，被一剑刺中，留下一道深深的伤口。\n" NOR;
                me->start_busy(3);
                target->start_busy(1);
                damage = (int)me->query_skill("sword");
                damage = random(damage)+damage;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/4);
                me->add("force", -100);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        return 1;
}
int perform2(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        msg = HIY "\n$p眼见$N露出破绽，急忙主动出击\n" NOR;
        message_vision(msg, me, target); 
       msg = HIC "谁知$N这招却是虚招，$p发现时为时已晚，被一剑刺中，留下一道深深的伤口。\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "$N顺势一抖手腕，手中剑柄击向$p\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "只见$p被剑柄敲得向后退出几步。\n" NOR;
                me->start_busy(3);
                target->start_busy(1);
                damage = (int)me->query_skill("sword");
                damage = damage+(int)me->query_skill("zixia-shengong", 1);
                damage = random(damage)+damage/2;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/4);
                me->add("force", -200);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        return 1;
}
int perform3(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        msg = HIY "\n$p眼见$N露出破绽，急忙主动出击\n" NOR;
        message_vision(msg, me, target); 
       msg = HIC "谁知$N这招却是虚招，$p发现时为时已晚，被一剑刺中，留下一道深深的伤口。\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "$N顺势一抖手腕，手中剑柄击向$p\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "只见$p被剑柄敲得向后退出几步。\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "$N顺势一转手中剑，一剑向$p横斩过来，在$p身上割出一道深可见骨的伤口。\n" NOR;
                me->start_busy(3);
                target->start_busy(1);
                damage = (int)me->query_skill("sword");
                damage = damage+(int)me->query_skill("force");
                damage = random(damage)+damage;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/4);
                me->add("force", -300);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        return 1;
}
int perform4(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        msg = HIY "\n$p眼见$N露出破绽，急忙主动出击\n" NOR;
        message_vision(msg, me, target); 
       msg = HIC "谁知$N这招却是虚招，$p发现时为时已晚，被一剑刺中，留下一道深深的伤口。\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "$N顺势一抖手腕，手中剑柄击向$p\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "只见$p被剑柄敲得向后退出几步。\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "$N顺势一转手中剑，一剑向$p横斩过来，在$p身上割出一道深可见骨的伤口。\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "趁此良机，$N向前跃起，左掌向$p猛击一掌，打得$p向后飞起。\n" NOR;
                me->start_busy(3);
                target->start_busy(1);
                damage = (int)me->query_skill("sword");
                damage = damage+(int)me->query_skill("force");
                damage = damage+(int)me->query_skill("unarmed");
                damage = random(damage)+damage;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/4);
                me->add("force", -400);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        return 1;
}
int perform5(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        msg = HIY "\n$p眼见$N露出破绽，急忙主动出击\n" NOR;
        message_vision(msg, me, target); 
       msg = HIC "谁知$N这招却是虚招，$p发现时为时已晚，被一剑刺中，留下一道深深的伤口。\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "$N顺势一抖手腕，手中剑柄击向$p\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "只见$p被剑柄敲得向后退出几步。\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "$N顺势一转手中剑，一剑向$p横斩过来，在$p身上割出一道深可见骨的伤口。\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "趁此良机，$N向前跃起，左掌向$p猛击一掌，打得$p向后飞起。\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "$N心中一片空明，竟然和剑一起向$p飞去，$p被一剑穿心而过，看来是活不成了。\n\n" NOR;
                me->start_busy(3);
                target->start_busy(1);
                damage = (int)me->query_skill("sword");
                damage = damage+(int)me->query_skill("force");
                damage = damage+(int)me->query_skill("unarmed");
                damage = damage+(int)me->query_skill("spells");
                damage = random(damage*2)+damage;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/2);
                me->add("force", -600);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        return 1;
}
