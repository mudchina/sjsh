#include <ansi.h>
inherit ROOM;
void create()
{
set ("short",HIC "寒 玉 床" NOR);
set ("long",@LONG

　　此床乃用冰山万年寒冰雕琢而成，有疗伤益寿之神奇功效，而且东暖夏凉。
看床的大小就知道是一张双人床，而且床的两侧还雕琢了九九八十一条神态各
异的龙与凤，由于万年寒冰自身灵气之故，上面的龙凤栩栩如生，这一切一切
乃神宫大仙用了九九八十一年心血努力而成。可见神宫大仙为这个家付出不少。
LONG);
set("exits",([
"out" : __DIR__"sleep",
]));
set("outdoors", 0);
set("no_fight", 1);
set("no_magic", 1);
set("no_clean_up", 1);
set("sleep_room",1);
set("if_bed",1);
setup();
}
