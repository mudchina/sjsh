//kunlun
inherit ROOM;

#include <ansi.h>
void create ()
{
       set ("short", "断崖");
        set ("long", @LONG

    这里看起来已经是无路可走了，前面是一条深深的
峡谷。
LONG);

	set("exits", ([ /* sizeof() == 2 */
                "north" : "/d/moon/yunu1",
        ]));
        set("objects", ([
   ]));
        set("outdoors", "kunlun");
	set("no_clean_up", 0);
        setup();
}
void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object ob;
        int new_sen;
        ob = this_player();
        new_sen = random( ob->query("max_sen")*3 );
        if ( new_sen > ob->query("sen") ) new_sen = ob->query("sen") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "down" )
                return notify_fail("你想要跳崖自杀？这么想不开啊？\n");
        tell_object(ob,HIR"你叹了口气，眼一闭，纵身往峡谷里跳去．．．\n"NOR);
        ob->move(__DIR__"qilin");
        tell_object(ob, HIW"你眼前一亮，原来这里竟然是一个世外桃源。\n"NOR);
        return 1;
}

