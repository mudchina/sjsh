//黯然消魂掌

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
      object weapon=me->query_temp("weapon");
      int enhance,damage;
      string str;

      if (!weapon) return 0;
      if( !target ) target = offensive_target(me);
      if( !target || !target->is_character()||target->is_corpse()||target==me)
          return notify_fail("你要攻击谁？\n");
      if (!me->is_fighting())
             return notify_fail("黯然消魂掌只能在战斗中使用！\n");
           
     if( time()-(int)me->query_temp("xiaohun_end") < 5 )
                   return notify_fail("你现在真气不纯。\n");      
     //if(me->query("family/family_name") != "盘丝洞")
       //         return notify_fail("[黯然消魂掌]是盘丝洞不传之密！\n");
                
     if (me->query_skill("qingxia-jian",1)<150)
          return notify_fail("你的青霞剑法太差，还不会出黯然消魂掌。\n");
      if (me->query_skill("lanhua-shou",1)<150) 
          return notify_fail("你的兰花手太差，还不会出黯然消魂掌。\n");
    if (me->query_skill("jiuyin-xinjing",1)<150)
        return notify_fail("你的九阴心法修为不够，还不会出黯然消魂掌。\n");
     if (me->query_skill_mapped("force")!="jiuyin-xinjing")
            return notify_fail("黯然消魂掌必须配合九阴心法才能使用。\n");
     if (me->query_skill_mapped("unarmed")!="lanhua-shou")
            return notify_fail("黯然消魂掌必须配合兰花手才能使用。\n");
      if (me->query("force")<150)
           return notify_fail("你内力不继，难以出招。\n");
    message_vision(HIM"\n$N回想当日爱人不禁黯然，不由的反身出掌。"NOR,me);
    //weapon->unequip();
    weapon->set_temp("original/use_apply_skill",weapon->query("use_apply_skill"));
    weapon->set_temp("original/skill_type",weapon->query("apply/skill_type"));
    weapon->set("use_apply_skill",1);
    weapon->set("apply/skill_type","unarmed");
    enhance=me->query_skill("lanhua-shou",1);
    me->add_temp("apply/attack", enhance);  
    damage=me->query_skill("jiuyin-xinjing",1);
    damage=damage/2;
    me->add_temp("apply/damage",damage);        
    COMBAT_D->do_attack(me, target);
    weapon->set("use_apply_skill",weapon->query_temp("original/use_apply_skill"));
    weapon->set("apply/skill_type",weapon->query_temp("original/skill_type"));
    me->add_temp("apply/attack",-enhance);
    me->add_temp("apply/damage",-damage);
    //weapon->wield();
    if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0))  
                       {str=target->name()+"被"+me->name()+"用盘丝洞绝招「黯然消魂掌」打死了，死的时候面上还有残留的泪痕！";
//                         message("channel:rumor",HIM"【空穴来风】某人："+str+"\n"NOR,users());
                       }
    me->reset_action();
    me->set_temp("xiaohun_end",time());
    return 1;
}

