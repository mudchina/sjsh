// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "青石街道");
  set ("long", @LONG

拥挤的东瀛街道，道路由青色小石铺成。人声鼎沸，街景秀丽，令人
目不暇己。两边有不少行人来回匆匆走过。北面便是著名的神谷道场,
在绯村剑心留在神谷道场后,道场的弟子是一天比一天多了起来。

LONG);

  set("exits", ([
        "west"    : __DIR__"dalu7",
        "east"    : __DIR__"dalu9",
        "north"     :__DIR__"wuguan",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 2,
          __DIR__"npc/zuozhizhu"    : 1,
      ]));

  set("outdoors",__DIR__"");
  setup();
}

