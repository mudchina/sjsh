// by Repoo
#include <ansi.h>
inherit ROOM;
void create ()
{
   set ("short", RED" 天神台 "NOR);
  set ("long", @LONG

这里是众神参禅修行的地方。远不见天，近不见地，
一切都是那么的虚无缥缈。

LONG);
  set("objects", ([
]));
  set("no_quit",1);
  set("no_flee",1);
  set("alternative_die",1);
  set("outdoors", 1);
  setup();
}
