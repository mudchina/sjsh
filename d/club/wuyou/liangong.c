inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","练功房");
  set ("long", @LONG
  
一个帮派，没有一个像样的练功房，怎么可以啊，所以这里的练功房
里面设备都很齐全，而且布置整洁，地方宽闯，甚可不用担心，放心
在这里练功啦。

LONG);

  set("exits",([
  "east" : __DIR__"juyitang",
  ]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("outdoors", 0);
  set("no_clean_up", 1);
  setup();
}