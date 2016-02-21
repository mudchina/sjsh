// gate.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "[1;37mÕ½½¢´óÌü[2;37;0m");
  set ("long", @LONG

ÕâËÒÕ½½¢ÊÇÖ¾Ö¾ĞÛÕæÊµÓÃÎäÁ¦¶áÈ¡Õû¸öÈÕ±¾ÖØÒªµÄµÀ¾ß£¬¶øÕâÀïÕıÊÇ
ÕûËÒÕ½½¢µÄÖ¸»ÓÖĞĞÄ¡£Ö¾Ö¾ĞÛÕæÊµºÍÓÉÃÀ×øÔÚ´óÌüµÄ¾¡Í·£¬ÓÃµĞÒâµÄ
ÑÛ¹â×¢ÊÓ×ÅÄã¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhanjianqianting",
  ]));
  
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhizhixiong" : 1,
  __DIR__"npc/youmei":1,
]));

  setup();
}
