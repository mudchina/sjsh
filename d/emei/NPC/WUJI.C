//change.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("�����޼�", ({"changkong wuji", "wuji","changkong"}));
       set("long","����ɽ��������������ܳ�������֮һ, ���׽��Ĵ��ˡ�\n");
       set("title", HIG"���������׽�����"NOR);
       set("gender", "����");
       set("age", 25);
       set("class", "xian");
       set("attitude", "friendly");
       set("per", 50);
	set("int", 30);
       set("max_kee", 3000);
       set("max_sen", 3000);
       set("sen", 3000);
       set("kee", 3000);
       set("max_gin", 600);
       set("max_force", 2000);
       set("max_mana", 2000);
       set("mana", 2000);
       set("force", 2000);
       set("force_factor", 100);
       set("mana_factor", 60);
       set("combat_exp", 4000000);
       set("daoxing", 3000000);
       set("eff_dx", 200000);
       set("nkgain", 350);
       set_skill("unarmed", 180);
       set_skill("literate", 180);
       set_skill("dodge", 180);
       set_skill("force", 180);
       set_skill("parry", 180);
       set_skill("sword", 180);
       set_skill("spells", 180);
       set_skill("leiyan-sword", 180);
       set_skill("emeiforce", 180);
       set_skill("zhutian-bu", 180);
       set_skill("mahayana", 180);
       set_skill("jinding-zhang", 180);
       map_skill("dodge", "zhutian-bu");
       map_skill("force", "emeiforce");
       map_skill("sword", "leiyan-sword");
       map_skill("parry", "leiyan-sword");
       map_skill("spells", "mahayana");
       map_skill("unarmed", "jinding-zhang");
       create_family("������", 3, "����");
 
 setup();
        carry_object("/d/lingtai/obj/heao")->wear();
        carry_object("/d/emei/obj/leiyan")->wield();
        
}

void attempt_apprentice(object ob)
{

        if( (string)ob->query("gender") != "����" )
	 {
		command ("say ����Ů��֮���޷�ѧϰ���׽�������ȥ����Ӣ��ѧϰ���ὣ�ɡ�");
		return;
        }
       
              if (((int)ob->query("combat_exp") < 500000 )) 
        { 
             command("say " + RANK_D->query_respect(ob) + "����ѧ��Ϊ���������Щ��ѧ�ط�������������\n"); 
              return;
        }

        if(((int)ob->query_skill("huifeng-sword",1) > 1))
        {
              command("say ��λ" + RANK_D->query_respect(ob) + "���㻹���ȷ�����ѧ�Ľ��������ܰ���Ϊʦ��");
              return;
        }


	 command("say �ã�ϣ��" + RANK_D->query_respect(ob) + "���Ŭ���������Ƕ��ҷ�����\n");
        command("recruit " + ob->query("id"));
        ob->set("title", HIG"���������׽�����"NOR);
}
