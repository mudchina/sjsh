// Room: /d/nanhai/xiaoyuan.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "̨��");
	set("long", @LONG
����ɽ�ŵ��ǰ����ƽ�е���ʯ̨��ͨ��ǰ����һ����
̨��̨���Ͼ����ο������룬���꣬�ɺ׵����ޣ���̬���涯
�ˡ���̨���з��Ÿ����˸ߵ���ͭ����¯��ǰ����Ÿ���̨��
��λ����������Ӱݡ�����ǰ���������
LONG );
	 set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/gunseng" : 1,
]));
  set("outdoors", "/d/nanhai");
  set("exits", ([ /* sizeof() == 4 */
              "south" : __DIR__"gate",
               "northup" : __DIR__"twdian",
               "west" : __DIR__"beilin2",
               "east" : __DIR__"beilin1",
]));
	set("outdoors", "/d/shaolin");
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "south" : (: look_door,     "south" :),
]));

create_door("south", "ʯ��", "north", DOOR_CLOSED);
  setup();
}