// 龟仙人 by Calvin

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name(HIW"龟仙人"NOR, ({"guei xianren","guei","xianren","shen","ren"}));
        set("title", HIG"龟仙岛"HIC"主人");
        set("gender", "男性" );
        set("age", 45);
        set("per", 30);
        set("str", 30);
set("long","他看起来一副老色狼样,杀气还很重。\n");

        set("attitude", "aggressive");

  set("combat_exp", 10000000);
  set("daoxing", 100000000);

  set_skill("literate", 300);
  set_skill("unarmed", 300);
  set_skill("force", 300);
  set_skill("lengquan-force", 300);
        set_skill("dengxian-dafa", 300);
     set_skill("gouhunshu", 300);
//   set_skill("meihua", 300);
  set_skill("whip", 300);
  set_skill("bawang-qiang", 300);
  set_skill("axe", 300);
  set_skill("dodge", 300);
  set_skill("parry", 300);
  set_skill("sanban-axe", 300);
  set_skill("bawang-qiang", 300);
  set_skill("spells", 300);
  set_skill("baguazhou", 300);
  set_skill("spear", 300);
  set_skill("yanxing-steps", 300);
  map_skill("force", "lengquan-force");
  map_skill("spells", "gouhunshu");
//        map_skill("spells", "dengxian-dafa");
  map_skill("axe", "sanban-axe");
  map_skill("parry", "sanban-axe");
  map_skill("dodge", "yanxing-steps");
  map_skill("spear", "bawang-qiang");
  map_skill("whip", "bawang-qiang");

  set("max_sen", 10000);
  set("max_kee", 10000);
  set("force", 12000); 
  set("max_force", 12000);
  set("force_factor", 500);
  set("max_mana", 10000);
  set("mana", 10000);
  set("mana_factor", 500);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "spear.lei" :),
                (: perform_action, "axe.sanban" :),
                (: perform_action, "axe.kai" :),
                (: exert_function, "jingxin" :),
                (: cast_spell, "gouhun" :),
                (: cast_spell, "inferno" :),
//                (: cast_spell, "tuntian" :),
//                (: cast_spell, "jieti" :),
        }) );
  set_temp("apply/armor", 50);
  set_temp("apply/dodge", 50);

  setup();
        carry_object("/d/calvin/obj/qianjuecao");
        carry_object("/d/longzhu/obj/1");
  carry_object("/d/longzhu/weapon/spear")->wield();
}

void die ()
{
    object me = this_object();
    object ob = query_temp("my_killer");
    object zhu;
    string zhu_given;
   zhu_given = "/d/longzhu/obj/1.c";
    ob->set_temp("npc/guei","done");
    if (!zhu_given->in_mud())
    {
   zhu = new("/d/longzhu/obj/1");
   zhu->move(ob);
 message_vision ("\n$N"HIY"被打的眼看不行了，$n立即从搜出了一颗龙珠... ...\n\n"NOR,me,ob);
message("channel:rumor",YEL+"\n【"+HIG" 龙珠传说 "NOR+YEL"】孙悟空："+ob->query("name")+"拿到"+HIW"白龙珠"NOR+YEL"了！\n\n"+NOR,users() );
  destruct (this_object());
  return ;
  }
else
  {
  message_vision ("$N"HIY"渐渐淡化了身影......\n"NOR,me);
  destruct (this_object());
  return ;
}
}
