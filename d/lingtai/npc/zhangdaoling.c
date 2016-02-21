//puti.c
inherit NPC;
inherit F_MASTER;
void consider();
void create()
{
       set_name("ÕÅµÀÁê", ({"zhang daoling", "zhang", "daoling"}));
       set("long", "ÕÅµÀÁêÄËÊÇÌìÉÏµÄÌìÊ¦£¬´Ë¿ÌÍµÏĞÔÚÉ½±ß¹Û¹Û¾°É«¡£\n");
       set("title", "ÌìÊ¦");
       set("gender", "ÄĞĞÔ");
	set("class", "taoist");
       set("age", 60);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("rank_info/respect", "ÀÏÉñÏÉ");
       set("per", 30);
	set("int", 30);
	set("str", 25);
       set("max_kee", 1000);
       set("max_gin", 1000);
       set("max_sen", 1000);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 40);
       set("max_mana", 1000);
       set("mana",1900);
       set("mana_factor", 50);
       set("combat_exp", 800000);
  set("daoxing", 1000000);


        set("eff_dx", 250000);
        set("nkgain", 400);



       set_skill("literate", 100);
       set_skill("unarmed", 105);
       set_skill("dodge", 135);
       set_skill("parry", 135);
	set_skill("sword", 135);
	set_skill("spells", 135);
	set_skill("dao", 120);
	set_skill("changquan", 120);
	set_skill("wuxiangforce", 120);
	set_skill("force", 120);
	set_skill("sanqing-jian", 135);
	set_skill("chaos-steps", 135);
	map_skill("spells", "dao");
	map_skill("unarmed", "changquan");
	map_skill("force", "wuxiangforce");
	map_skill("sword", "sanqing-jian");
	map_skill("parry", "sanqing-jian");
	map_skill("dodge", "chaos-steps");
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: consider :)
        }) );



create_family("åĞÒ£ÅÉ", 1, "À¶");
setup();

        carry_object("/d/lingtai/obj/heao")->wear();
	carry_object("/d/lingtai/obj/faguan")->wear();
        carry_object("/d/obj/weapon/sword/qingfeng");
}

void attempt_apprentice(object ob)
{
	if ( (string)ob->query("family/family_name")=="·½´çÉ½ÈıĞÇ¶´") {
	command("say RANK_D->query_respect(ob) + ÒÑÊÇÉí´¦ÃûÃÅ£¬»¹Ğè¶à¼ÓÅ¬Á¦²ÅÊÇ£¬Ôõ¿ÉÓÖÍ¶ÎÒÃÅÏÂ£¿\n");
	return;
	}
	command("shake");
	command("say ÀÏ·ò²»ÊÕÍâÃÅµÜ×Ó£¬È´¿ÉÖ¸µãÄãÒ»ÌõÃ÷Â·£¬ÕâÉ½ÉÏÓĞ¸öÀÏÉñÏÉ£¬·¨Á¦ÎŞ±ß£¬ÄãÍ¶±¼ËûÈ¥°É£¡\n");
        return;
}

void die()
{

        if( environment() ) {
        message("sound", "\n\nÕÅµÀÁêÁ³É«Í»±ä£¬µÀ£ºÌìÉÏµãÃ®£¬Ë¡²»·îÅã£¡\n\n", environment());
	command("drop all");
	message("sound", "\nÕÅµÀÁê»¯³ÉÒ»¹É×ÏÑÌ³åÉÏÌìÈ¥¡£¡£¡£\n\n", environment());
        }

        destruct(this_object());
}

int accept_fight(object me)
{	me= this_object();
	if( (int)me->query("kee")*100/(int)me->query("max_kee") >= 50 ) {
		if( (int)me->query("kee")*100/(int)me->query("max_kee") >= 90 ) {
		
			command("say ºÃ°É£¬²»¹ıÀÏ·òÂíÉÏ¾ÍÒª×ßÁË£¬Ö»¶·Æ¬¿Ì£¡\n");
        		command("unwield sword");
        		command("enable unarmed none");
			return 1;
			}
		command("say ºÃ°É£¬²»¹ıÀÏ·òÂíÉÏ¾ÍÒª×ßÁË£¬Ö»¶·Æ¬¿Ì£¡\n");
               	command("wield sword");
                command("enable unarmed changquan");
               	return 1;
	}
        command("say Á¼¾°ÈçË¹£¬ÎŞĞÄ¶·¶ø¡£\n");
        return 0;
}

void consider()
{

        int i, flag = 0;
        object *enemy;

        enemy = query_enemy() - ({ 0 });
        for(i=0; i<sizeof(enemy); i++) {
                if( !living(enemy[i]) ) continue;
                        flag++;
                if(     !query_temp("weapon") ) {
                command("say ¸óÏÂ¹¦·ò³¬Èº£¬ÀÏµÀÖ»ºÃ¶¯´ÖÁË£¡\n");
                        command("wield sword");
			command("enable unarmed changquan");
                        break;
                }
        }
}

ÿ