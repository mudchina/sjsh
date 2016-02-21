// 三重门

#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", "生死门");
        set ("long", @LONG
这里是地下城的第二道门-生死门-,再往下便是-还魂门-。
破烂的墙上写着:
                   ********************
                   ****生***死***门****
                   ********************
LONG);

        set("exits", 
        ([ //sizeof() == 4
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/milin/npc/shengsi" : 1,
        ]));

        set("no_quit", 1);
        setup();
}

void init()
{
        add_action("do_wa", "wa");
}

int do_wa()
{
        object  me, horse;
        me = this_player();
/*        
        if(me->query_temp("ridee")){
                horse=me->query_temp("ridee");
                me->command_function("dismount "+horse->query("id"));
        }
*/
message_vision(HIY "$N使劲的挖啊挖,累的满头是汗。忽然只见$N身边一道黑光,之后就不见了身影。\n" NOR, me);
        me->move("/d/milin/qy/huanhun");
        message_vision(HIY "只见$N浑身黑土,狼狈的掉了下来。\n" NOR, me);
        me->receive_damage("kee", 100);
        me->receive_damage("sen", 100);
        return 1;
}
