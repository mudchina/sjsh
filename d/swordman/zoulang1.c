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
  "north" : __DIR__"zoulang2",
  "south" : __DIR__"zhanjian1",
  ]));
  
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 2,
]));

  setup();
}
int valid_leave(object me, string dir)
{       if (dir == "north") {
        if((string)me->query("title")!=WHT"Ê®±¾ÈĞ½£¿Í"NOR){
        if (objectp(present("jian ke", environment(me))))
        return notify_fail("Ê®±¾ÈĞ½£¿Íºá½£µ²ÔÚÃæÇ°£ºÉÃ´³Ë½ÈËÖØµØ£¬Õâ²»ÊÇÕÒËÀÂğ£¿\n");

        }

        return ::valid_leave(me, dir);
        }
        return ::valid_leave(me, dir);

}
