// 猪八戒
// by Calvin and Leox 共同开发
// 版权所有,未经许可不得翻录

inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
  set_name(HIC "猪八戒" NOR, ({ "zhu bajie", "zhu", "bajie" }));
  set("title", HIW "天蓬元帅" NOR);
  set("age", 600);
  set("gender", "男性");
  set("long", "嘿嘿，连老猪都不认识啦？\n");
        set("class", "tianpeng");
        create_family("天蓬元帅府", 1, "祖师");
        set("rank_info/respect", "祖师");
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 10);
  set("combat_exp", 2000000);
  set("daoxing", 2000000);

  set("max_kee", 2500);
  set("max_sen", 2500);
  set("max_force", 2500);
  set("force", 2500);
  set("force_factor", 150);
        set("mana", 2500);
        set("max_mana", 2500);  
  set("mana_factor", 150);
  set_skill("unarmed", 220);
  set_skill("dodge", 220);
  set_skill("parry", 220);
  set_skill("rake", 220);
  set_skill("force", 220);
  set_skill("spells",220);
  set_skill("skyriver-rake", 220);
  map_skill("rake", "skyriver-rake");

        set_temp("apply/damage", 50);
        set_temp("spply/armor", 50);
        set_temp("apply/dodge", 50);
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
//                (: cast_spell, "juanbi":),
//                (: cast_spell, "tuntian" :),
//                (: perform_action, "sword", "chaofeng":),
       }) );

            setup();

  carry_object("/d/leox/weapon/pa")->wield();
  carry_object("/d/obj/armor/jinjia")->wear();
}

void attempt_apprentice(object ob)
{
        if( (string)ob->query("class")=="bonze" && (string)ob->query("gender")=="男性"  )
        {
                command("kick " + ob->query("id"));
                command("say 快走，快走！我一看到和尚就有气。\n");
                return;
        }

        if( (string)ob->query("family/family_name")=="天蓬元帅府" ){
                if( (int)ob->query("family/generation") > 3   ){
                        command("say 没有左右亲信的推荐，本座很难考虑。\n");
                }
                else {
                        if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 1200000 ){
                                command("nod ");
                                command("say 好，" + RANK_D->query_respect(ob) + "好好跟我干，将来大有可为！\n");
                                command("recruit " + ob->query("id") );
                        }
                        else {
                                command("say 你还是找其他弟子先练着吧。\n");
                        }
                }
        }

        else{
                command("hmm");
                command("say 这位" + RANK_D->query_respect(ob) + "，我这可不是一下子就可以当老大的。\n");
        }

        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "tianpeng");
}

void init()
{       
        object ob=this_player();

        ::init();
        if ( ((string)ob->query("gender")=="男性") && ((string)ob->query("class")=="bonze") && 
(random(3) > 1) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        switch( random(1) ) {
                case 0:
                        command("sorry" + ob->query("id"));
                        command("say 我不想再收和尚做徒弟了,上辈子我已经够苦的了！");
                        break;
        }
}
