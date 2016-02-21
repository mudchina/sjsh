// gate.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "[1;37mÕ½½¢Ç°Ìü[2;37;0m");
  set ("long", @LONG

ÕâËÒÕ½½¢ÊÇÖ¾Ö¾ĞÛÕæÊµÓÃÎäÁ¦¶áÈ¡Õû¸öÈÕ±¾ÖØÒªµÄµÀ¾ß£¬ÔÙÍùÇ°È¥±ã
ÊÇÕûËÒÕ½½¢µÄÖ¸»ÓÖĞĞÄ¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zoulang3",
   "north":__DIR__"zhanjiandating",
  ]));
  
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zongcilang" : 1,
]));

  setup();
}
int valid_leave(object me, string dir)
{       if (dir == "north") {
        if((string)me->query("title")!=WHT"Ê®±¾ÈĞ½£¿Í"NOR){
        if (objectp(present("zongcilang", environment(me))))
        return notify_fail("×Ú´ÎÀÉÎ¢Ğ¦×ÅËµµÀ£ºÖ¾Ö¾ĞÛ´óÈË²»ÏëÓĞÈË´ò½Áµ½Ëû£¬ËùÒÔÇë»Ø°É¡£\n");

        }

        return ::valid_leave(me, dir);
        }
        return ::valid_leave(me, dir);

}
