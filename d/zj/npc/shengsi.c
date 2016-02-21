// ÉúËÀ¶ñÉñ by Calvin

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIM"ÉúËÀ¶ñÉñ"NOR, ({"shengsi eshen", "eshen", "shen"}));
       set("long",
"ÈıÖØÃÅÖ®Ò»´óÊØ»¤Éñ,ÓĞ×Å¸ßÉîÄª²âµÄ¹¦Á¦¡£\n");
       set("title", HIC"ÈıÖØÃÅÉñÖ®"NOR);
       set("gender", "Å®ĞÔ");
       set("age", 30);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "ÏÉ¹Ã");
       set("per", 40);
	set("int", 30);
       set("max_kee", 10000);
       set("max_gin", 10000);
       set("max_sen", 10000);
       set("force", 5000);
       set("max_force", 5000);
       set("force_factor", 300);
       set("max_mana", 5000);
       set("mana", 5000);
       set("mana_factor", 300);
       set("combat_exp", 10000000);
  set("daoxing", 8000000);


        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 350);
       set_skill("unarmed",350);
       set_skill("dodge", 350);
       set_skill("force", 350);
       set_skill("parry", 350);
       set_skill("sword", 350);
       set_skill("spells", 350);
        set_skill("moonshentong", 350);
        set_skill("baihua-zhang", 350);
        set_skill("moonforce", 350);
        set_skill("snowsword", 350);
        set_skill("moondance", 350);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("sword", "snowsword");
        map_skill("parry", "snowsword");
        map_skill("dodge", "moondance");

create_family("ÔÂ¹¬", 1, "¿ªÉ½×æÊ¦");
setup();

//        carry_object("/d/milin/obj/ssd");
        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/moon/obj/feijian")->wield();
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="Å®ĞÔ")){
           command("shake");
           command("say ÎÒÃÇÔÂ¹¬Ö»ÊÕÅ®Í½£¬ÕâÎ»" +
RANK_D->query_respect(ob) + "»¹ÊÇÁíÇë¸ß¾Í°É¡£\n");
           return;}
        if ( (int)ob->query("per") <30){
	  command("shake");
	command("say ÒÔÎÒ¿´ÕâÎ»" +
RANK_D->query_respect(ob) + "µÄ×ÊÖÊ²¢²»ÊÊÓÚÌøÎè£¬»¹ÊÇÁíÇë¸ß¾Í°É¡£\n");
  ob->set_temp("denied_by_chang_e",1);
	return;
}

        command("pat "+ob->query("id"));
        command("say ºÃ£¬Ï£Íû" + RANK_D->query_respect(ob) +
"¶à¼ÓÅ¬Á¦£¬°ÑÎÒÃÇÔÂ¹¬·¢Ñï¹â´ó¡£\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xian");
}


ÿ
