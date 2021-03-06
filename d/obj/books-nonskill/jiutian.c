// 三重门九重天之书 by Calvin

inherit ITEM;

#include <ansi.h>

int do_kan(string arg);
void create()
{
  set_name("《兰陵传说》", ({"lanling story","lanling","book"}));
  set_weight(200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "本");
    set("value", 1000);
    set("no_drop", 1);
    set("long", " 《兰陵传说》 请用 kan 阅读(1-n)。\n");
    set("material", "paper");
  }
}

void init()
{
  add_action("do_kan", "kan");
}

int do_kan(string arg)
{
  object me = this_player();
  object ob = this_object();
  int size = 100;
  int nb=0;

  ob->set("value", 1000);

  if (arg == "new") return 0; 
  if (! arg || sscanf(arg, "%d", nb)!=1)
  {
    write("\n");
    me->start_more(read_file("/d/obj/books-nonskill/text/llindex"));
    write("\n");
    write ("请用 kan <number> 参阅有关章节(1-n)。\n");
    return 1;
  }

  if ( nb <= 0 || nb > size)
    return notify_fail ("你要读哪一章？\n");

  else 
  {  
  write("\n");
  if (nb<0 && file_size("d/obj/books-nonskill/text/ll0"+nb) >= 0) 
      me->start_more(read_file("d/obj/books-nonskill/text/ll0"+nb));
  else if (file_size("d/obj/books-nonskill/text/ll"+nb) >= 0)
      me->start_more(read_file("d/obj/books-nonskill/text/ll"+nb));
  else write("尚未输入，请稍候。");
  write("\n");
  return 1;
  }
}
