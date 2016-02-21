// Room: /d/wiz/menpai_room
inherit ROOM;
#include <ansi.h>;

void create ()
{
  set ("short", "海上飘的新门派讨论室");
  set ("long", 

"这里是幻想巫师海上飘的工作室，在这里巫师们可以讨论发展
新门派的事宜，讨论各门派发展平衡等各种问题的。您如果有什么
好的意见或想法；如果因为某事您找不到我请"HIY"ＰＯＳＴ"NOR"下面的留言
板。我会尽快与您联系的，谢谢。"HIC"———  "HIR"海上飘
"HIC"\n海上飘正在作的新门派如下：

"HIW" 游 侠 "HIC"（已完成"HIR"99.9%"HIC"）
\n"NOR
 );

  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/city/kezhan",
   "east" : __DIR__"jobroom", 
]));
  set("light_up", 1);
  set("no_magic", 1);

  setup();
  call_other("/obj/board/menpai_b", "???");
}
