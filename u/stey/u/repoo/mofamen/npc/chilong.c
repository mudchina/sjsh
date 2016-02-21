// repoo
#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIY"赤龙"NOR, ({ "chi long", "long", "dragon" }) );
        set("gender", "男性" );
        set("long",HIC
                "赤龙城守卫！\n"NOR);
 
        set("age",50);
         set("nickname", HIW"『龙城护卫』"NOR);
         set("title", HIB"八部天龙"NOR);
        set("attitude", "heroism");
        set("str",40);
        set("int",30);
        set("max_kee",3100);
        set("kee",3100);
        set("max_sen",3100);
        set("sen",3100);
        set("combat_exp",2500000);
      set("daoxing",4500000);
        set("force",5000);
        set("max_force",3000);
        set("mana",5000);
        set("max_mana",3000);
   set("force_factor",150);
        set("mana_factor",120);
        set("eff_dx", 4500000);
        set("nkgain", 1500);
        set_skill("unarmed",180);
        set_skill("dragonfight", 180);
        set_skill("parry",180);
        set_skill("dodge",180);
              set_skill("dragonstep",180);
        set_skill("fork",180);
        set_skill("fengbo-cha",180);
        set_skill("force",180);
              set_skill("dragonforce",200);
        set_skill("spells", 180);
        set_skill("seashentong", 180);
              map_skill("force","dragonforce");
              map_skill("spells", "seashentong");
        map_skill("dodge", "dragonstep");
        map_skill("parry", "fengbo-cha");
        map_skill("fork","fengbo-cha");
        map_skill("unarmed", "dragonfight");
        set("inquiry", ([
                "name" : "在下赤龙，奉谕把守赤龙城。",
                        ]) );
    //    set("chat_chance_combat", 50);
        //      set("chat_msg_combat", ({
       //         (: perform_action,"unarmed","sheshen" :),
      //          (: cast_spell, "dragonfire" :),                
     //   }) );
              setup();
        carry_object("/d/sea/obj/longpao")->wear();
   //     carry_object("/d/obj/weapon/hammer/jingua")->wield();
}
void kill_ob (object ob)
{
  object me = this_object();
  set_temp("my_killer",ob);
  call_out ("xue",8+random(8),me,ob);  
  ::
kill_ob(ob);
}
void xue (object me, object ob)
{
  object huobing;
  int damage;
  if (! me)
    return;
  if( !living(me) )
    return;
  if (! ob)
    return;
  if (environment(ob) != environment(me))
    return;
  message_vision ("$N"HIW"张开大嘴，低声念了几声咒语，顿时风起云涌，一片冰雪向$n罩来！\n"NOR,me,ob);
  if ( ((int)ob->query_skill("dodge", 1)+ random(100)) > 240 )
     message_vision (HIC"$N纵身跃到半空中，闪过了这一击。\n"NOR,ob);
 else 
    {
     message_vision (HIW"结果$N被冻住不能行动！\n"NOR,ob,me);
     ob->start_busy(3+random(5));
    } 
  remove_call_out ("xue");  
  call_out ("xue",random(10)+10,me,ob);  
}
void die ()
{
  object me = this_object();
   object ob = query_temp("my_killer");
  object yi;
  string longyi_given;
  longyi_given = "/u/repoo/mofamen/obj/longyi.c";
     ob->set_temp("chilong_killed",1);
   ob->delete_temp("chilong_killing");
   if (!longyi_given->in_mud())
         {
  yi = new("/u/repoo/mofamen/obj/longyi");
  yi->move(ob);
   message_vision ("$N"HIY"惊慌逃窜，连翅膀都忘记带走....\n"+HIM"一对翅膀掉在了$n身上。\n"NOR,me,ob);
 message("channel:rumor",YEL+"\n【"+HIB" 八部天龙 "NOR+YEL"】某人："+ob->query("name")+"拿到"+HIY"赤龙"+HIB"之翼"NOR+YEL"了！\n\n"+NOR,users() );
  destruct (this_object());
  return ;
       }
    else
       {
  message_vision ("$N"HIY"化作一股清风......\n"NOR,me);
  destruct (this_object());
  return ;
}
}
