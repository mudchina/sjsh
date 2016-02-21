//shulin 兰陵

inherit ROOM;

void create ()

{
        set ("short", "精华台");
        set ("long", @LONG

你跳下千紫藤来到了天的顶端,这里鸟瞰大地,一切是那么的
渺小,这里有无数的宝物,可惜需要很大的本领才可以带走这
些宝物,其中的一棵"千绝草(qianjue cao)"据说如果吃下去
的话好象对自己的修为有所帮助！ ... ...
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
        ]));

        set("objects", 
        ([ //sizeof() == 8
             "/u/calvin/npc/shouhu.c" : 1,
//               "/d/calvin/obj/feng.c" : 1,
//               "/d/calvin/obj/hou.c" : 1,
//               "/d/calvin/obj/shuei.c" : 1,
//               "/d/calvin/obj/tu.c" : 1,
//               "/d/calvin/obj/lei.c" : 1,
              "/d/calvin/npc/gueiwei.c" : 1,
        ]));

//        set("outdoors", "lanling");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

void init()
{
object who=this_player();
add_action("do_error", "mark");
}

int do_error(string arg)
{
object who = this_player();
message_vision("这里好象不可以乱留痕迹吧!\n",who);
return 1;
}

