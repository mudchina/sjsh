// laozhe.c

#include <ansi.h>

inherit NPC;

void create()
{
       set_name(HIG"老者"NOR, ({"lao zhe", "laozhe"}));
       set("long", "一个悠闲的老人家，坐在树下乘凉。\n");
       set("title", HIC"方寸山三星洞"NOR);
       set("gender", "男性");
       set("age", 1000);
       set("class", "wusheng");
       set("attitude", "friendly");
       set("shen_type", 1);
//       set("rank_info/respect", "护法");
       set("looking", "英俊潇洒，玉树临风，风流倜傥。");
       set("max_kee", 1000);
       set("max_gin", 100);
       set("max_sen", 1000);
       set("force", 1000);
       set("max_force", 500);
       set("force_factor", 10);
       set("max_mana", 500);
       set("mana", 1000);
       set("mana_factor", 10);
       set("combat_exp", 500000);
       set("daoxing", 1100000);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("spells", 100);  
        set_skill("dao", 100);
        set_skill("literate", 100);
        set_skill("sword", 100);  
        set_skill("wuying", 100);
        set_skill("fumobashi", 100);  
        set_skill("mizongbu", 100);
        set_skill("dodge", 100);  
        set_skill("force", 100);   
        set_skill("wuxiangforce", 100);

        map_skill("spells", "dao");
        map_skill("unarmed", "fumobashi");
        map_skill("force", "wuxiangforce");
        map_skill("sword", "wuying");
        map_skill("parry", "wuying");
        map_skill("dodge", "mizongbu");

	setup();
	carry_object("/d/obj/armor/jinjia")->wear();

}

�
