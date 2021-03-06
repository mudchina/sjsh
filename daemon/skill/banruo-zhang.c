//banruo-zhang.c 【般若掌】weiqi
//menpai skill(non manpai NPCs can also use it)

inherit SKILL;
#include <ansi.h>;

mapping *action = ({
        ([      "action":
"$N前腿踢出，后腿脚尖点地，一式"+BLINK""+HIW"「横空出世」"NOR+"，二掌直出，攻向$n的上中下三路",
                "dodge":                -5,
                "parry":                -5,
	    "force":		80,
                "damage_type":  "瘀伤",
        "skill_name" : "横空出世"
]),
        ([      "action":
"$N左掌划一半圆，一式"+BLINK""+HIW"「长虹贯日」"NOR+"，右掌斜穿而出，疾拍$n的胸前大穴",
                "dodge":                -25,
                "parry":                -25,
	    "force":		70,
                "damage_type":  "瘀伤",
        "skill_name" : "长虹贯日"
]),
        ([      "action":
"$N使一式"+BLINK""+HIW"「云断秦岭」"NOR+"，右掌上引，左掌由后而上一个甩劈，斩向$n的$l",
                "dodge":                -5,
                "parry":                -5,
	    "force":		60,
                "damage_type":  "瘀伤",
        "skill_name" : "云断秦岭"
]),
        ([      "action":
"$N左掌护胸，右拳凝劲后发，一式"+BLINK""+HIW"「铁索拦江」"NOR+"，缓缓推向$n的$l",
                "dodge":                5,
                "parry":                5,
	    "force":		60,
                "damage_type":  "瘀伤",
        "skill_name" : "铁索拦江"
]),
        ([      "action":
"$N使一式"+BLINK""+HIW"「狂风卷地」"NOR+"，全身飞速旋转，双掌一前一后，猛地拍向$n的胸口",
                "dodge":                -5,
                "parry":                -5,
	    "force":		90,
                "damage_type":  "瘀伤",
        "skill_name" : "狂风卷地"
]),
        ([      "action":
"$N合掌抱球，猛吸一口气，一式"+BLINK""+HIW"「怀中抱月」"NOR+"，双掌疾推向$n的肩头",
                "dodge":                5,
                "parry":                5,
	    "force":		60,
                "damage_type":  "瘀伤",
        "skill_name" : "怀中抱月"
]),
        ([      "action":
"$N向上高高跃起，一式"+BLINK""+HIW"「高山流水」"NOR+"，居高临下，掌力笼罩$n的全身",
                "dodge":                5,
                "parry":                5,
	    "force":		80,
                "damage_type":  "瘀伤",
        "skill_name" : "高山流水"
]),
        ([      "action":
"$N使一式"+BLINK""+HIW"「摘星换斗」"NOR+"，劲气弥漫，双掌如轮，一环环向$n的$l斫去",
                "dodge":                -5,
                "parry":                -5,
	    "force":		80,
                "damage_type":  "瘀伤",
        "skill_name" : "摘星换斗"
]),
              ([      "action":
"$N两掌上下护胸，一式"+BLINK""+HIW"「翻江搅海」"NOR+"，骤然化为满天掌雨，攻向$n",
                "dodge":                -5,
                "parry":                -5,
	    "force":		60,
                "damage_type":  "瘀伤",
        "skill_name" : "翻江搅海"
]),
              ([      "action":
"$N一式"+BLINK""+HIW"「金刚伏魔」"NOR+"，双手合十，对着$n微微一揖，全身内劲如巨浪般汹涌而出",
                "dodge":                -5,
                "parry":                -5,
	    "force":		100,
                "damage_type":  "瘀伤",
       "skill_name" : "金刚伏魔" 
]),

});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("练摧心掌必须空手。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("kee", 30);
	me->add("force", -10);

	return 1;
}

string perform_action_file(string func)
{
return CLASS_D("shaolin") + "/banruo-zhang/" + func;
}
