//技能医术 by koker@sjsh 2001
/*三界神话V2.0版本*/
 
inherit SKILL;
#include <ansi.h>

string exert_function_file(string func)
{
        return "/daemon/class/jineng/medical/" + func;
//医术是可以疗毒和疗内伤的。
}

int valid_learn(object me)
{
   object ob;
//每增加一级等级可以学4级医术技能。
   if ((int)me->query_skill("medical", 1) > ( (int)me->query("level")*4))
    return notify_fail(""HIW"你的等级不够,不能继续学习医术这样技能了。"NOR"\n");

   return 1;
}



