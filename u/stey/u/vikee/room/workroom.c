#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "山中小亭");
    set("long", 
"这里是一叶知秋工作的地方:\n\n"
HIY "           秋风瑟瑟\n"
    "           落叶飘飘\n\n"
HIG "     电子信箱:vikee@263.net\n\n" NOR
);
set("sleep_room", 1);
        set("no_death", 1);
        set("valid_startroom", 1);
        set("exits", ([
            "down" :"/d/city/kezhan.c",
            "up" :"/d/wiz/wizroom.c",
            "city" :"/d/city/center.c",
            "lg" :"/d/sea/gate.c",
        ]));
        replace_program(ROOM);
}
