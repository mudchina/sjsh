//cheng yaojin, updated 5/7/97, pickle

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int ask_baishi();

void create()
{
  set_name(HIC"ÏàÀÖ×ôÖ®Öú"NOR, ({ "master xiangle", "xiangle", "zuozhizhu", "master"}));
  set("title", HIY"´ò¼Ü×¨¼Ò"NOR);
  set("gender", "ÄÐÐÔ");
  set("age", 25);
  set("str", 60);
  set("per", 20);
  set("cor", 40);
  set("cps", 35);
  set("long","
Ä»Ä©Ê±³à±¨¶ÓµÄÔ¤±¸¶ÓÔ±£¬ÔÚ¶Ó³¤ÏàÀÖ×ÜÈýËÀÓÚÎ¬ÐÂÕþ¸®ÊÖÏÂ
ºó£¬±ã¿ªÊ¼ÁËÒÔ´ò¼ÜÎªÉúµÄÀËÈËÉúÑÄ¡£ÒÂ·þ±³ºóÐåµÄ¡°¶ñ¡±×Ö
ÒÔ¼°¡°Õ¶×ó¡±µÄ³ÆºÅ£¬ÈÃËùÓÐµÐÈËÎÅ·çÉ¥µ¨¡£
");
  set("combat_exp", 5000000);
    set("daoxing", 7000000);

  set_skill("unarmed", 240);
  set_skill("kongshoudao", 240);
  set_skill("force", 180);
  set_skill("guixi-force", 180);
  set_skill("dodge", 180);
  set_skill("parry", 180);
  set_skill("spells", 140);
  set_skill("renshu", 140);
  set_skill("sword", 140);
  set_skill("fengyu-piaoxiang", 180);
  map_skill("force", "guixi-force");
  map_skill("spells", "renshu");  
  map_skill("unarmed", "kongshoudao");
  map_skill("dodge", "fengyu-piaoxiang");
  set("max_sen", 2000);
  set("max_kee", 2000);
  set("force", 5000); 
  set("max_force", 2500);
  set("force_factor", 500);
  set("max_mana", 3000);
  set("mana", 1500);
  set("mana_factor", 100);
  set("inquiry", ([
	"°ÝÊ¦"     : (: ask_baishi :),
]) );

  create_family("½£¿ÍÁªÃË", 2, "µÜ×Ó");
  set("chat_chance", 2);
  set("chat_msg", ({ (: random_move :) }));

  setup();
  carry_object("/d/obj/cloth/zhanpao")->wear();
}


int ask_baishi()
{  
  object ob=this_player();
   if (ob->query("family/master_id")=="master xiangle" )
  {
	command("say ÄãÒÑ¾­ÊÇÎÒµÜ×ÓÁË£¬»¹ÎÊ¸ÉÊ²Ã´¡£");
	return 1;
   }
    else
     {
   command("say ÄãÈç¹ûÄÜ¶ã¹ýÎÒÈýÕÐ£¬ÎÒ¾ÍÊÕÄãÎªÍ½¡£Äã¿ÉÔ¸ÒâÊÔÊÔ£¿(try)£¿");
      this_player()->add_temp("swordman/ask_zuozhizhu",1);
   return 1;
      }
}

void init()
{
    object ob;
    ::init();
        add_action("do_agree", "try");
}

int do_agree()
{
    mapping guild;
    int skee,dkee;
    object me,target;
	
	me=this_player();
	target=this_object();
	skee=me->query("kee");
     if (!me->query_temp("swordman/ask_zuozhizhu"))
       return 0;
       me->delete_temp("swordman/ask_zuozhizhu");
    if(time() - me->query("swordman/try_zuozhizhu")<72000)
   {
          command("say ÎÒÃÇ¸Õ´òÍê£¬¹ýÁ½ÌìÔÙ´ò¡£");
          return 1;
   }
  if (me->query_temp("swordman/zuozhizhu")==1 )
  {
	command("say ÏÖÔÚÎÒÃ»ÐËÈ¤ºÍÄã´ò¡£");
	return 1;
   }
    command("say ¹þ¹þ£¬ÓÐµ¨×Ó£¡");
    me->set("swordman/try_zuozhizhu",time());
    COMBAT_D->do_attack(target, me);
    dkee=me->query("kee");
    if((dkee<skee) 
     || !present(me, environment()))
    {
	command("kick");
       command("say Äã»¹ÊÇ»ØÈ¥¶àÁ·Ï°Á·Ï°µÄºÃ¡£");
	return 1;
    }
    command("say ²»´í£¬ÔÙ½ÓÕâÕÐ¿´¿´£¡");
    COMBAT_D->do_attack(target, me);
    dkee=me->query("kee");
    if((dkee<skee) 
    || !present(me, environment()))
    {
	command("say ÄÜ±Ü¹ýÎÒÒ»ÕÐÒÑËã²»´í¡£");
	return 1;
    }
    command("say ¿´²»³öÄã´ò¼ÜµÄ¹¦·ò»¹Í¦²»´íµÄ£¡");
    COMBAT_D->do_attack(target, me);
    dkee=me->query("kee");
    if((dkee<skee) 
    || !present(me, environment()))
    {
	command("say ¿ÉÏ§Äã¾Í²îÔÚÕâ×îºóÒ»ÕÐÁË¡£");
	return 1;
    }
    me->add_temp("swordman/zuozhizhu", 1);
    command("say ¹ûÈ»ºÃÉíÊÖ¡£");
    command("say ºÜ¾ÃÃ»ÓÐÕâÑùÍ´¿ìµÄ´òÒ»¼ÜÁË£¬ÎÒ¾Í°Ñ¿ÕÊÖµÀ´«ÊÚ¸øÄã°É¡£");
     command("haha");
     command("say ºÃºÃÅ¬Á¦¡£\n");
     command("recruit " + me->query("id") );
    return 1;
}

int accept_fight(object me)
{
  command("say ÕýºÃÎÒºÜ¾ÃÃ»»î¶¯½î¹ÇÁË¡£");
  return 1;
}

void attempt_apprentice(object me)
{
  if (me->query_temp("swordman/zuozhizhu")!=1)
  {
   command("say ÎÒµÄ¿ÕÊÖµÀ¿É²»Ëæ±ã´«¸ø±ðÈË¡£");
   return 0;
  }
  command("haha");
  command("say ºÃºÃÅ¬Á¦¡£\n");
  command("recruit " + me->query("id") );
    me->delete_temp("swordman/zuozhizhu");
  return;
}

int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
  ob->set("class", "swordman");
}
ÿ
