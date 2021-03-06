
//huifeng-jian.c 回风拂柳剑

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([	  "name":   "清风袭月",
	"action" : "$N剑尖剑芒暴长，一招"+BLINK""+HIC"「清风袭月」"NOR"，手中$w自左下大开大阖，
一剑向右上向$n的$l",
	"force" : 120,
	"dodge" : 20,
	"damage" : 300,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([	  "name":   "飘雪穿云",
	"action" : "$N长剑圈转，一招"+BLINK""+HIM"「飘雪穿云」"NOR"，手中$w平展下刺，一剑轻轻划
过$n的$l",
	"force" : 120,
	"dodge" : 20,
	"damage" : 280,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([	  "name":   "千峰竞秀",
	"action" : "$N长剑轻灵跳动，剑随身长，右手$w使出一式"+BLINK""+HIG"「千峰竞秀」"NOR"刺向$n的
$l",
	"force" : 140,
	"dodge" : 15,
	"damage" : 350,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([	  "name":   "万流归宗",
	"action" : "$N长剑下指，剑意流转，一招"+BLINK""+HIC"「万流归宗」"NOR"直取$n的$l",
	"force" : 150,
	"dodge" : 15,
	"damage" : 280,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([	  "name":   "乌龙搅柱",
	"action" : "$N剑芒吞吐，幻若灵蛇，右手$w使出一式"+BLINK""+HIB"「乌龙搅柱」"NOR"，剑势曼妙，
刺向$n的$l",
	"force" : 130,
	"dodge" : 25,
	"damage" : 300,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([	  "name":   "大雁啼沙",
	"action" : "$N屈腕云剑，剑光如彩碟纷飞，幻出点点星光，右手$w使出一式
"+BLINK""+HIM"「大雁啼沙」"NOR"跃跃洒洒飘向$n的$l",
	"force" : 120,
	"dodge" : 25,
	"damage" : 320,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([	  "name":   "进退龙游",
	"action" : "$N挥剑分击，剑势自胸前跃出，右手$w一式"+BLINK""+HIB"「进退龙游」"NOR"，毫无
留恋之势，刺向$n的$l",
	"force" : 110,
	"dodge" : 15,
	"lvl" : 0,
	"damage" : 400,
	"damage_type" : "刺伤"
]),
([	  "name":   "天地鹤翔",
	"action" : "$N退步，左手剑指划转，腰部一扭，右手$w一记"+BLINK""+HIM"「天地鹤翔」"NOR"自下
而上刺向$n的$l",
	"force" : 150,
	"dodge" : 35,
	"damage" : 400,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练回风拂柳剑。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
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

int practice_skill(object me)
{
	int flvl=(int)me->query_skill("force");
	int slvl=(int)me->query_skill("sword");

	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的内力或气不够，没有办法练习回风拂柳剑。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按著所学练了一遍回风拂柳剑。\n");
	if(random(slvl)>flvl)
		me->improve_skill("force", 1);
	return 1;
}
string perform_action_file(string func)
{
return CLASS_D("emei") + "/huifeng-sword/" + func;
}

