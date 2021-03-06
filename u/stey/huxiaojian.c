// huxiaojian.c 【虎啸皇剑】

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"action":		"$N一抖手中的$w，使出一招"HIR"「一啸红尘惊」"NOR"，瞬间刺出三十六剑，$n顿时手忙脚乱，分不清虚实",
		"dodge":		-10,
                "parry":                -20,
		"damage":		35,
		"damage_type":		"刺伤"
	]),
	([	"action":		"$N一剑刺向$n，使出一招"HIC"「再啸湖海翻」"NOR"，$n急忙向旁边一闪，\n不料$N一运劲儿，手中的$w突然弯了过来，转而刺向$n的$l",
		"dodge":		-20,
                "parry":                -10,
		"damage":		50,
		"damage_type":		"刺伤"
	]),
	([	"action":		"$N手中$w连续划出几个光环，一阵吸力带得$n向前踏出一步，$N左手剑指已刺向$n的$l，正是一招"HIB"「三啸鬼神辟」"NOR,
		"dodge":		-20,
                "parry":                -20,
		"damage":		55,
		"damage_type":		"刺伤"
	]),
	([	"action":		"第四招"HIW"「绝啸穹苍灭」"HIW"，$N一转身，背向$n，手中$w从腋下反手刺向$n的$l",
		"dodge":		-10,
                "parry":                -10,
		"damage":		60,
		"damage_type":		"刺伤"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练虎啸皇剑。\n");
	if( !(ob = me->query_temp("weapon")) ||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
	return CLASS_D("sanjie")+"/huxiaojian/"+action;
}

int practice_skill(object me)
{
	int flvl=(int)me->query_skill("force");
	int slvl=(int)me->query_skill("sword");

	if( (int)me->query("kee") < 30 || (int)me->query("force") < 3 )
		return notify_fail("你的内力或气不够，没有办法练习虎啸皇剑。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按著所学练了一遍虎啸皇剑。\n");
	if(random(slvl)>flvl)
		me->improve_skill("force", 1);
	return 1;
}

int stage(int level)
{
	if( level <60 ) return 1;
	else if ( level < 120 ) return 2;
	else if ( level < 180 ) return 3;
	else return 4;
}

string level_description(int level)
{
	if ( stage(level) < 1 )
		return HIR "第"+chinese_number( stage(level) )+"层　" NOR;
	else if ( stage(level) < 2 )
		return HIC "第"+chinese_number( stage(level) )+"层　" NOR;
	else if ( stage(level) < 3 )
		return HIB "第"+chinese_number( stage(level) )+"层　" NOR;
	else 
		return HIW "第"+chinese_number( stage(level) )+"层　" NOR;
}

void skill_improved(object me)
{
   int m_skill=me->query_skill("sanqing-jian",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对虎啸皇剑的领悟加深了，你的虎啸皇剑进入了一个新的境界！\n"NOR);

     if(random(me->query("kar"))<20){
        tell_object(me,HIW"然而你的心中居然产生了一种失落感！\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然福至心灵，对虎啸皇剑领悟出了一招新的用法！\n"NOR);
     tell_object(me,"请为这招取一个名字：");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}

void name_skill(object me, string arg)
{
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=me->query("skill_sanqing-jian");
 if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"刺伤"]);

   if(!arg||arg==" ")arg="虎啸皇剑绝技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIB"「"+arg+"」"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_sanqing-jian",m_actions);
}