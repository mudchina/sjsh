// longma-steps.c by angell

inherit SKILL;

string *dodge_msg = ({
        "$n一招「马跃壇溪」身行拔地而起，避了开去。\n",
        "只见$n身影一晃，一式「白驹过隙」早已避在七尺之外。\n",
        "$n使出「或跃在渊」，连跳了几下，闪了开去。\n",
        "$n左足一点，一招「潜龙腾渊」腾空而起，避过了这一击。\n",
        "可是$n使一招「马失前蹄」，单膝跪倒，很浪漫的躲了过去。\n",
        "$n身影微动，已经藉一招「神龙见首」轻轻闪过。\n",
        "但是$n一招「龙腾马跃」使出，身形早已不见！\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练龙马步法。\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("你的气或内力不够，不能练龙马步法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}
