// dan.c ������

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY"��ʥ������"NOR, ({ "dan" }) );
        set("long",
HIY"��ʥ�������ϳ˵��鵤��ҩ��\n"NOR);
        set("unit", "��");
        set("weight", 5);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("��Ҫ��ʲ�᣿\n");

          if( living( this_player())==0) return 0;

          if( living( this_player())==0) return 0;

        ob=this_player(); 
        ob->set_skill("force",80);
        ob->set_skill("parry",80);
        ob->set_skill("dodge",80);
        ob->set_skill("sword",80);
        ob->set_skill("unarmed",80);
        ob->set_skill("literate",50);
        ob->set_skill("feisheng",50);
        ob->set_skill("fumobashi",50);
  ob->set_skill("mizongbu",50);
     ob->set_skill("spells",80);
        ob->set_skill("wuying",50);
        ob->set_skill("xiantian",50);
write(HIY+"�����һ��������������ֻ����һ�����������������!��ʱ�����ʥ�ŵ��书��������\n"NOR);

        message("vision", HIY + ob->name() + 
"����һ��������������ֻ����һ������������������!��ʱ������ʥ�ŵ��书��������\n"NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}