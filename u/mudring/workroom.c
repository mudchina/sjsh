// Room: /u/mudring/workroom.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","蝶之谷");
  set ("long", @LONG

............................................................................................
............................................................................................
............................................................................................
............................................................................................
............................................................................................

LONG);
  set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/wiz/wizroom",
  "down" : "/d/city/kezhan",
]));
  set("valid_startroom", 1);
set("outdoors", "蝴蝶谷");
  setup();
}

void init()
{
    if (this_player()->query("id") != "mudring")
        message_vision("$N偷偷溜了过来。\n", this_player());
    if (this_player()->query("id") != "mudring")
        message_vision("四周响起一片“打倒"+this_player()->name(1)+"”的口号声，$N假装没听见。\n", this_player());
}

int clean_up()
{
    return 0;
}

void reset()
{
        tell_room(this_object(), BLINK+HIR"Reset.\n"NOR);
        ::reset();
}

