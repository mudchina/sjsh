#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "水果店");
  set ("long", @LONG

水果店里的水果真多啊,很远就闻到香了
据老板说这里的水果都是这土生土长的
好吃的不得了的!
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
    "south" : "/u/calvin/room/密林深处3",
]));

  setup();
}
