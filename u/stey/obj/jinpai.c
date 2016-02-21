// jinpai.c 金牌

#include <ansi.h>

inherit ITEM;
int do_eat(string);                                                                         
void init();
   
void create()
{
	set_name(HIY "金牌" NOR, ({ "jin pai", "pai"}) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗金光闪闪的金牌，令人羡慕不已。\n");
                set("value", 100000);
		set("unit", "个");
	}
	 set("is_monitored",1);
	 setup();   
}

void init()
{
	if (!wizardp(this_player())) {                                                            
    set("no_get",1);                                       
    set("no_give",1);                                        
    set("no_drop",1);                                        
    set("no_sell",1);
    }
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object victim = this_player();

        if (! id(arg))
                return 0);

        me = this_player();
        message_vision(HIM "$N拿起一个金牌，顿时倍感自豪，浑身舒畅！ \n" 
        NOR, me);
        me->add("potential, 10000);
        destruct(this_object());
	return 1;
}
