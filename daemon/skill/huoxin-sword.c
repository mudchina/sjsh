#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使一招"+BLINK""+HIW"「冰刃」"NOR",手中$w带着霍霍剑光，宛如细雨点点将$n的$l照在无尽的剑光下",
                "dodge":                -50,
                "damage":               40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出神谷活心流中的"+BLINK""+HIC"「霜华」"NOR"剑光如飞花片片般地斩向$n的$l",
                "dodge":                -40,
                "damage":               30,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一招"+BLINK""+WHT"「瞬雪」"NOR"身形陡然凌空弹开数尺，手中的$w徒然斩向$n的$l",
                "dodge":                -50,
                "damage":               20,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w中宫直进，一式"+BLINK""+HIM"「冰镜」"NOR"对准$n的$l猛的刺出数剑",
                "dodge":                -40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N纵身一跃，手中$w一招"+BLINK""+MAG"「垂斩」"NOR"对准$n的$l斜斜刺出一剑",
                "dodge":                -70,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N的$w凭空一指，猛然变换招式，一招"+BLINK""+HIW"「树冰」"NOR"刺向$n的$l",
                "dodge":                20,
                "damage":               40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w向外一分，使一招"+BLINK""+BLU"「雪风」"NOR"反手对准$n$l一剑刺去",
                "dodge":                -40,
                "damage":               60,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N横剑上前，身形一转手中$w使一招"+BLINK""+HIC"「水月」"NOR"画出一道光弧刺向$n的$l",
                "dodge":                -30,
                "damage":               50,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，没有办法练神谷活心流。\n");
//        if(me->query("title") != "神谷道场弟子")
          if(me->query("family/master_id") != "master xun" &&  me->query("family/master_id") != "master miyan")
                return notify_fail("你按着所学练习了一遍神谷活心流，但似乎总掌握不到剑术的要领。\n");



        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
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

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return 
notify_fail("你的内力或气不够，没有办法练习神谷活心流。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所学练了一遍神谷活心流。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("swordman") + "/huoxin-sword/" + action;
}
 
int effective_level() { return 15;}

string *parry_msg = ({
        "$n使出一招「冷月」，手中的剑化作一条长虹，磕开了$N的$w。\n",
        "$n使出「飞花」诀，将$N的$w封于丈外。\n",
        "$n使出一招「秋水」，手中的剑化做漫天蛇影，荡开了$N的$w。\n",
        "$n手中的剑一抖，一招「白雪」，向$N拿$w的手腕削去。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的剑舞得密不透风，封住了$N的攻势。\n",
        "$n反手一招「飞花」，整个人消失在一团剑光之中。\n",
        "$n使出一招「落叶」，剑直刺$N的双手。\n",
        "$n将手中的剑化做七条剑气，宛如瑟瑟秋风，迫得$N连连后退。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

