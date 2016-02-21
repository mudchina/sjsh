// jingang.c

#include <ansi.h>

inherit NPC;

void create()
{
	object ob1, ob2;
	
        string *order = ({"����", "����", "�ǻ�", "�̴", "����", "����", "����", "����", "����"});

        set_name((order[random(9)]) + "�޺�", ({ "luohan"}) );
        set("long", "����һλ���������µ�ʮ���޺���ר�ŵ��λ���֮��\n");
	set("attitude", "friendly");

        set("max_gin", 1000);
        set("max_kee", 1000);
        set("max_sen", 1000);

        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force", 1000);
        set("force", 1000);

	set("str", 40);
        set("cor", 40);
        set("cps", 40);

        set("combat_exp", 800000);
        set_skill("zui-gun", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("stick", 100);
        set_skill("shaolin-shenfa", 100);

	map_skill("dodge", "shaolin-shenfa");
	map_skill("stick", "zui-gun");
	map_skill("parry", "zui-gun");
        setup();

        ob1=carry_object("/d/shaolin/obj/xuan-cloth");
	ob1->wear();
	ob1->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n");
        ob2=carry_object("/d/shaolin/obj/qimeigun");
	ob2->wield();
	ob2->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n");
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",
               HIY + name() + "˵����ĩ�޺�����ٻ��������Ѿ���ɻ������񣬾ʹ˸�ǣ�\n\n"
                + name() + "����һƬ��⣬��ʧ�����ˡ�\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

void invocation(object who)
{
	int i;
	object *enemy;

	message("vision",
                HIY "ֻ���䣡��һ����һ�Ž��һ�����ֳ�һ����������������ִ�������޺���\n\n"
                + name() + "˵����ĩ�޺�����ٻ�������������\n" NOR,
		environment(), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	set_leader(who);
}