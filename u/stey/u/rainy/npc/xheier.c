#include <ansi.h>
inherit NPC;
void create()
{ set_name(HIG"小黑儿"NOR,({"xheier"}));
set("long","一个黑黑壮壮的青年，你一望他，他就朝你“或或”的傻笑。\n");
set("title",HIG"夜心阁－香坊总管"NOR);
set("gender","男性");
set("per",24);
set("age",18);
set("str",35);
set("con",30);
set("int",30);
set("max_kee", 1000);
set("eff_kee", 1000);
set("kee", 1000);
set("max_force",2000);
set("force",400);
set("combat_exp", 1000000);
set("inquiry",([
"heier": "我是澜舟的哥哥，这个香水坊的主管，有什么事尽管问我吧.....\n",
"小黑儿": "我是澜舟的哥哥，这个香水坊的主管，有什么事尽管问我吧.....\n",
"job": "我是澜舟的哥哥，妹妹说晚上“夜水心”的异香会招来很多小偷，她让我帮她管着这片香水坊，盛情难却，所以，我小黑儿就站在这儿了......\n",
]));
setup();
carry_object("/u/rainy/obj/staff")->wield();
}
