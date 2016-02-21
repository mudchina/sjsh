// Room: /changan/mufa.c

inherit ROOM;

void create ()
{
  set ("short", "木船");
  set ("long", @LONG

木船在海中航行，四周是白茫茫的一片汪洋。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"haian.c",
]));
set("zuo_trigger", 0);
  set("outdoors", 1);

  setup();
}
