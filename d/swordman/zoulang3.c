// gate.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "[1;37mÕ½½¢×ßÀÈ[2;37;0m");
  set ("long", @LONG

³¤³¤µÄÕ½½¢×ßÀÈ£¬Òõ°µ»ŞÉ¬£¬Á½ÖÜÌø¶¯µÄ»ğ°Ñ¹âÁÁ¸ü¸øÕû¸öÕ½½¢ÌíÉÏ
ÁË¹îÃØµÄÉ«²Ê¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zhanjianqianting",
  "south" : __DIR__"zoulang2",
  ]));
  
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yushui" : 1,
]));

  setup();
}
int valid_leave(object me, string dir)
{       if (dir == "north") {
        if((string)me->query("title")!=WHT"Ê®±¾ÈĞ½£¿Í"NOR){
        if (objectp(present("yushui", environment(me))))
        return notify_fail("ÓîË®ºá½£µ²ÔÚÃæÇ°£ºÄÜ¹»Ç¿¹ıÎÒµÄ»°£¬±ã¿ÉÒÔ´ÓÕâ¹ıÈ¥¡£\n");

        }

        return ::valid_leave(me, dir);
        }
        return ::valid_leave(me, dir);

}
