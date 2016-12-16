// 神话世界·西游记之（世纪）
 
// create by jing 2000.7.13

inherit ROOM;

void create ()
{
  set ("short", "街道");
  set ("long", @LONG

街道虽然不是很宽，但是人来人往的也是一片繁荣的景象，北面是一家花
店，据说那里有各种各样的鲜花出售。东面就是蠙城的中心广场，人来人
往十分热闹，那里传来阵阵喧哗声。南面是一家酒店，不时有交觥之声传
来。

LONG);

  set("exits", ([
        "east"   : __DIR__"center",
        "west"   : __DIR__"jiedao2",
        "north"   : __DIR__"huapu",
        "south"   : __DIR__"jiudian",
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

