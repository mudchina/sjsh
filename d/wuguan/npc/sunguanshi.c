//Cracked by Roath
// sunguanshi.c ¹¤¾ß·¿¹ÜÊÂ--ÀÏËï
// by yfeng


#include <ansi.h>

inherit NPC;
int give_tool();

void create()
{
	set_name("Ëï¹ÜÊÂ", ({ "sun guanshi","guanshi","sun" }));
	set("gender", "ÄĞĞÔ");
	set("age", 38);
	set("chat_chance", 25);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set("combat_exp", 70000);
	set("shen_type", 1);
	set("inquiry", ([
		"tool": 	(: give_tool:),
		"¹¤¾ß": 	(: give_tool:)
		]));

	setup();
	carry_object(__DIR__"obj/qingcloth")->wear();
}

int give_tool()
{
	object ob=this_player();
	object me=this_object();
	
	return JOB_OB("wuguan")->give_tool(ob,me);
}

void init()
{
	object ob=this_player();
	
	::init();
	
	remove_call_out("greeting");
	call_out("greeting",1,ob);
	return;
}

int accept_object(object ob,object obj)
{
	object me=this_object();
	
	return JOB_OB("wuguan")->accept_tool(me,ob,obj);
}

int greeting(object ob)
{
	if(!ob || (environment(ob)!=environment())) return 0;
	command("say ´ó¼ÒÒª¸É»î£¬¾ÍÕÒÎÒÒª¹¤¾ß"+HIY"(ask sun about tool)"NOR+"¡£"ÌpC#Œ6¢°'<
