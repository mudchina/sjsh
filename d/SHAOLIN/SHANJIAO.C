
inherit ROOM;

void create ()
{
	set ("short", "少室山脚下");
	set ("long", @LONG

    来到少室山脚下，行了一程，忽听得水声如雷，峭壁上两条玉龙直挂
下来，双瀑并泻，屈曲回旋，飞跃奔逸。自瀑布之侧上峰，你不禁暗赞少
室山之灵秀。
LONG);


	set("exits", 
	([ //sizeof() == 4
                "west" : "/d/kaifeng/wutaishan/guandao",
         "northup" : __DIR__"shijie7",
	]));
	
	set("objects", 
	([ //sizeof() == 1
//               __DIR__"npc/jieding" : 1,
	]));


        set("outdoors", 1);

	setup();
}


