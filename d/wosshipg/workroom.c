// Room: /d/wiz/punish.c

inherit ROOM;
#include <ansi.h>

void create()
{
set("short", HIR"Ìý·ç¸ó"NOR);
          set("long", HIG@LONG
      !!!!!!!!»¶Ó­À´µ½ÌúÂí±ùºÓÈëÃÎÀ´µÄË½ÈË±ðÊû!!!!!!!!!!!

¡ö¡ö¡ö¡ö¡ö      ¡ö¡ö¡ö¡ö¡ö 
¡öÌïÌïÌï¡ö¡¡¡¡¡¡¡öÌïÌïÌï¡ö¡¡
¡öÌïÌïÌï¡ö©¶¡¡¡¡¡öÌïÌïÌï¡ö©¶¡¡¡¡"ÊÀ¼Í»¨Ô°"
¡öÌïÌïÌï¡ö©¾¡¡¡¡¡öÌïÌïÌï¡ö©¾¡¡¡¡¡¡¡¡
¡öÌïÌïÌï¡ö¡¡¡¡¡¡¡öÌïÌïÌï¡ö¡¡¡¡¡¡¡¡¡¡¡ø¡¡¡¡
¡öÌïÌïÌï¡ö¡¡¡¡¡¡¡öÌïÌïÌï¡ö¡¡¡¡¡¡¡¡¡ø¡ø¡ø¡¡¡¡¡ö¡þ¡þ¡þ¡ö
¡ö©±©Ô©¶¡ö¡¡¡¡¡¡¡ö©²©Ô©¶¡ö¡¡¡¡¡¡¡ø¡ø¡ø¡ø¡ø¡¡¡ö¡¡¡¡¡¡¡ö
¡ö©§©¦©§¡ö¡¡¡¡¡¡¡ö©§©¦©§¡ö¡¡¡¡¡¡¡¡¡¡¡ø¡¡¡¡¡¡¡ö¡¡¡¡¡¡¡ö
¡ö¡ö¡ö¡ö¡ö¡ø¡ø¡ø¡ö¡ö¡ö¡ö¡ö¡ø¡ø¡ø¡ø¡ø¡ø¡ø¡ø¡ø¡ö¡¡¡¡¡¡¡ö
LONG NOR );

set("objects", ([
                __DIR__"obj/rack": 1,
]) );
  set("chat_room",1);
        set("valid_startroom", 1);
                set("exits", 
        ([ //sizeof() == 4
                "kz" :   "/d/city/kezhan",
                "jail":  "/d/wiz/punish",
                "wiz" :  "/d/wiz/wizroom",
                "wdd" :  "/d/qujing/wudidong/kitchen",
                "guest" :"/d/wiz/guest",
        ]));


        setup();

}
void init()
{   
        if (!wizardp(this_player())) 
             add_action("block_cmd","",1);      
        else
             add_action("read_book","read");
}

int block_cmd()
{
        string verb = query_verb();

        if (verb=="say") return 0; //allow say
        if (verb=="help") return 0;
        if (verb=="chat") return 0;//allow chat
        if (verb=="rumor") return 0;//allow rumor
//        if (verb=="quit") return 0;
        if (verb=="look") return 0;
        return 1;
}
int valid_leave(object me, string dir)
{
        object mbox;

        if( mbox = me->query_temp("mbox_ob") ) {
                tell_object(me, "Äã½«ÐÅÏä½»»Ø¸øÓÊ²î¡£\n");
                destruct(mbox);
        }

        return ::valid_leave(me, dir);
}

int read_book(string arg)
{
   if (!arg) return 0;
   if (arg!="death" && arg!="call" && arg!="mon" ) return 0;
   if (arg=="death") {
                if(file_size("/log/death")>0)
                this_player()->start_more( read_file("/log/death"));
        }
   if (arg=="call") {
                if(file_size("/log/static/call_player")>0)
                this_player()->start_more( read_file("/log/static/call_player"));
        }
   if (arg=="mon") {
                if(file_size("/log/monitord")>0)
                this_player()->start_more( read_file("/log/monitord"));
        }       
   write("\n");   
      return 1;
}
