// zong guan vikee.c
// created by vikee 2000.11

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(""HIY"ÏÉÂÂÇéÔµÅÅÐÐ°ñ"NOR"", ({"score"}));
}

void init()
{
  add_action("do_read","read");
//  add_action("do_list","list");
}

//int do_list(string arg)
//{
//string type;
//  type="/adm/daemons/toptend"->query_type();
//  write(type);
//  return 1;
//}

int do_read(string type)
{
 write("/adm/daemons/toptend"->topten_query(type));
return 1;

}