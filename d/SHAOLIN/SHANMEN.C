// Room: /d/shaolin/shanmen.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "������ɽ��");
    set("long", @LONG
һ���޴���Ʒ��������Ƭɽ��֮�䣬�Ʒ����Ϸ���������
������֣��������¡����ּ���Щ���䣬����ȥ�����Զ����λ
��ʮ�����ɮ���ֳֽ䵶����ɽ�����ࡣ�������һ��ʯ����
LONG );
    set("exits", ([ /* sizeof() == 4 */
            "eastup" : __DIR__"shijie8",
        "west" : __DIR__"shijie7",
    ]));
set("outdoors", 1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
