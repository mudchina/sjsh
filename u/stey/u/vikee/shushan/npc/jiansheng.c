//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
       set_name(HIC"��ʥ"NOR, ({ "jian sheng", "sheng", "swordsman" }));
        set("title","");
        set("long", 
"��ɽ���������ˣ���ͷ�׷������ˣ������൱����\n");

        set("gender", "����");
        set("age", 65);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("per", 20);
        set("class","swordsman");
        
        set("kee", 4000);
        set("max_kee", 4000);
        set("sen", 3000);
        set("max_sen", 3000);
        set("force", 8000);
        set("max_force", 5000);
        set("max_mana",5000);
        set("mana",8000);
        set("force_factor", 100);
        set("mana_factor", 100);
        set("combat_exp", 3000000);
        set("daoxing", 5000000);

        set_skill("spells",170);
        set_skill("force", 180);
        set_skill("dodge", 150);
        set_skill("parry", 160);
        set_skill("sword", 200);
        set_skill("zixia-shengong", 180);
        set_skill("sevensteps", 170);
        set_skill("hunyuan-zhang", 160);
        set_skill("literate", 140);
        set_skill("unarmed", 160);
        set_skill("mindsword", 200);
        set_skill("shushan-jianfa", 200);
        set_skill("taoism",170);
        map_skill("spells", "taoism");
        map_skill("dodge", "sevensteps");
        map_skill("force", "zixia-shengong");
        map_skill("parry", "mindsword");
        map_skill("sword", "mindsword");
        map_skill("unarmed", "hunyuan-zhang");


        create_family("��ɽ����", 4, "������");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword","xindong" :),
                (: cast_spell, "jianshen" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
   add_temp("apply/damage", 135);
   add_temp("apply/attack", 135);
   add_temp("apply/dodge", 135);
   add_temp("apply/spells", 100);
   add_temp("apply/armor", 150);
   add_temp("apply/armor_vs_force",250);
   add_temp("apply/armor_vs_spells",250);
  set("inquiry", ([
        "leave": (: expell_me :),
        ]) );
        setup();
        
        carry_object("/d/obj/cloth/jinpao")->wear();
        carry_object("/d/obj/weapon/sword/qingfeng")->wield();
}
void attempt_apprentice(object ob)
{        
	if (ob->query_skill("sword",1) < 130) {
        command("say ����ɽ���ɣ���ע�������������У����ҿ�" + RANK_D->query_respect(ob) + "�ǲ��Ǹö����¿๦�أ�");
                return ;
        }
        if ((int)ob->query_int() < 35) {
        command("say ���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺ�ѧ����ɽ�����书��");
                return;
        }
        
        if (ob->query("shushan/ask_zuidao_go")) {
        if (ob->query("nyj/shushan")!="done"){
                command("say " + RANK_D->query_respect(ob) + "�����ȻҪΥ���Ź�ȥ�������������Ҹ��ҽ�ʥѧ��ɽ�����书��");
                return;
        }
        command("say ���⣬�������⣡");
        
        }
        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
        ob->set("class", "swordsman");
        ob->set("title","��ʥ����");
}
string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="��ɽ����")
    {
      me->set_temp("betray", 1);
      command("sigh");
      return ("������ɽ�Ź棬ȴ���ܷ������Ը��(agree)��");
    }
  return ("�Ҳ�֪����");
}
void init()
{
  add_action("do_agree", "agree");
}
int do_agree(string arg)
{
  if(this_player()->query_temp("betray"))
    {
      message_vision("$N���������Ը�⡣\n\n", this_player());
      command("say �����ȥ�ɡ����������������⣡");
      this_player()->add("betray/count", 1);
      this_player()->add("betray/shushan", 1);
      this_player()->delete_skill("taoism");
      this_player()->delete_skill("zixia-shengong");
      this_player()->delete_skill("shushan-jianfa");
      this_player()->delete_skill("canxin-jian");
      this_player()->delete_skill("dugu-jiujian");
      this_player()->delete_skill("yirubian");
      message_vision("��ʥ��$N��ͷ������һ�£�$N��ʱ����������ʧ��\n\n", this_player());
      this_player()->delete("family");
      this_player()->set("title", "��ɽ��ͽ");
      this_player()->save();
      return 1;
    }
  return 0;
}