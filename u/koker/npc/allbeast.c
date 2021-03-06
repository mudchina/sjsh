// all_beast.c

inherit NPC;

void create(int level,int damage,int armor)
{
	string temp;
	int flag,num;
	num=3;
	flag=random(num);
	switch(flag)
	{
	case 0:
		set_name("大耳怪",({"goblin"}));
		temp=sprintf("拿着鬼头刀的怪物！\n");
		break;
	case 1:
		set_name("超级大耳怪",({"super goblin"}));
		temp=sprintf("拿着鬼头刀的怪物！\n");
		break;
	case 2:
		set_name("顶级大耳怪",({"gold goblin"}));
		temp=sprintf("拿着鬼头刀的怪物！\n");
		break;
	default:
		set_name("初级魔法师",({"magicman"}));
		temp=sprintf("会魔法的怪物！\n");
		break;
	}

	set("race", "野兽");
	set("age", 4);
	set("long", temp);
	set("attitude", "aggressive");
	
	set("str", 20+random(20));

	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("level", level);
	
	

	set_temp("apply/damage", damage);
	set_temp("apply/armor", armor);

	setup();

	switch(flag)
	{
	case 0:
		break;
	case 1:
		carry_object("/u/wosshipg/axe")->wield();
		break;
	case 2:
		carry_object("/u/wosshipg/spear")->wield();
		break;
	case 3:
		carry_object("/obj/weapon/sword")->wield();
		break;
	case 4:
		carry_object("/u/wosshipg/staff")->wield();
		break;
	}

}
