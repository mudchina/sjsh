//changan city

inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","ʮ�ֽ�ͷ");
  set ("long", @LONG

������ǳ����ǵ����ģ�������ֽ����ڴˡ�һ��Ρ��ߴ����¥��
����ǰ��������Щ���ơ�ÿ���峿�����������������ŵ���������
�򳤰��ǵĴ��С�·�ڳ�ˮ�����������˳����ϡ�
LONG);

        set("exits", 
        ([
	"south" : __DIR__"zhuque-s1",
        "north" : __DIR__"xuanwu-n0",
        "west" : __DIR__"baihu-w1",
        "up" : __DIR__"jiuguan1",
        "east" : __DIR__"qinglong-e1",
        "down" : __DIR__"droproom",
        ]));
        set("objects", 
        ([
         "/d/longzhu/npc/libai" : 1,
//         "/u/admin/npc/nushen" : 1,
//       "/u/stey/baobao1" : 1,
	"/d/qujing/wuzhuang/npc/zhangguolao": 1,
        ]));

	set("outdoors", 1);
	setup();
}
