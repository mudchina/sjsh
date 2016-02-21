#include <ansi.h>
#include <dbase.h>
#include <armor.h>
inherit F_AUTOLOAD;  
inherit NECK;
void create()

  {
     set_name(RED"ÓÀÔ¶µÄÃµ¹å"NOR, ({ "mei gui" ,"flower","hua" }) );
     set_weight(100);
      set("long","sorry,°®ÄãµÄÒ¶×Ó.\n");
     set("value", 0);
      set("material", "flower");
     set("no_drop", "¶àÆ¯ÁÁ£¬Áô×Å°É¡£\n");
     set("unit", "¶ä");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 5);
     setup();
  }

int query_autoload() { return 1; }
