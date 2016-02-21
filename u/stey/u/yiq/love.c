// Room: /moon/wroom.c
//cglaem...12/13/96.

#include <ansi.h>

inherit ROOM;
#include <ansi.h>

void create ()
{
    set ("short",HIG "田园春晓" NOR);
  set ("long", @LONG

   这是衣青的卧室。
一缕早春的阳光透过木窗栏投进了室内。室外早起的鸟儿已经开始唧唧喳喳了，
似乎想把你唤醒。墙上新作的字还在散发着墨香－爱－这是衣青亲手写的，虽然
七倒八歪的写得很难看，但是他似乎非常喜欢，每天都欣赏足三个小时。
小屋中间有一张素净的床(bed)。
LONG);

  set("no_fight", 1);
  set("objects",
 ([
 __DIR__"hua.c" : 1,
 __DIR__"obj/zuanjie" : 1,
  "u/rainy/hunsha" : 1,
 
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "bed" : "睡觉用的床铺(gosleep,gobed,bed)。 
",
]));
  set("exits", ([ /* sizeof() == 1 */
    "down" : __DIR__"workroom",
           "pig" :  "/u/rainy/workroom",
]));
  set("no_magic", 1);

  setup();
}

void init()
{
        add_action("do_bed", "gosleep");
        add_action("do_bed", "gobed", );
        add_action("do_bed", "bed");
}

int do_bed()
{       object me;
        me=this_player();
        message_vision(HIY "$N掀开纱帐，准备上床了。\n\n" NOR, me);
          me->move(__DIR__"bed");
            message_vision(HIY "\n纱帐轻轻一动，$N钻了进来。\n" NOR, me);
                return 1;
}
