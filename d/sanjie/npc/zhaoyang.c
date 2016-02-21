// zhaoyang.c ³¯ÑôÌìÊ¦

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
       set_name(HIR"³¯ÑôÌìÊ¦"NOR, ({"master zhaoyang", "master"}));
       set("long", "ÌìÒ»¹¬ÕÆÃÅ´óÊ¦ĞÖ£¬µÂ¸ßÂ¡ÖØ£¬¹óÎªµÀ½ÌÃËÖ÷¡£\n");
       set("title", HIC"ÌìÒ»¹¬"NOR);
       set("per", 40);
       set("gender", "ÄĞĞÔ");
       set("age", 70);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "ÀÏµÀ³¤");
       set("max_kee", 1500);
       set("max_gin", 100);
       set("max_sen", 1500);
       set("force", 1800);
       set("max_force", 1800);
       set("force_factor", 180);
       set("max_mana", 1800);
       set("mana", 1800);
       set("mana_factor", 180);
       set("combat_exp", 1700000);
       set("daoxing", 2100000);

        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("spells", 220);  
        set_skill("tianmogong", 120);
        set_skill("literate", 120);
        set_skill("sword", 120);  
        set_skill("huxiaojian", 120);
        set_skill("zhaoyangbu", 120);
        set_skill("force", 120);   
        set_skill("huntianforce", 120);

        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("sword", "huxiaojian");
        map_skill("parry", "huxiaojian");
        map_skill("dodge", "zhaoyangbu");

	
	create_family("Èı½çÉ½", 2, "À¶");
	
	set("inquiry", ([
        "³öÃÅ"    : (: expell_me :),
        "leave"   : (: expell_me :),
	"name"     : "ÎÒÄËÌìÒ»¹¬ÏÖÈÎÕÆ½Ì´óµÜ×Ó£¬Äã¿ÉÒÔ³ÆºôÎÒ³¯ÑôÌìÊ¦¡£\n",
	"here"     : "ÕâÀïÊÇÌìÒ»¹¬ºóµî£¬ÄãÃÔÂ·ÁË£¿\n",
	]));	
	
	setup();
	carry_object("/d/sanjie/obj/jinjia")->wear();
	carry_object("/d/sanjie/obj/qinghong")->wield();
}

string expell_me(object me)
{       
        me=this_player();
        if((string)me->query("class")=="sanjie") {
                message_vision("³¯ÑôÌìÊ¦ºú×Ó¶¶¶¶£¬ºÃÏñ·Ç³£ÉúÆø¡£\n", me);
                me->set_temp("sj_betray", 2);
                message_vision("³¯ÑôÌìÊ¦¶Ô$NÈÂÈÂ×Å£ºĞ¡¶«Î÷£¬ÄãËµ»°ÊÇÕæĞÄ»°(true)£¿\n", me);
                return ("ÆøËÀÎÒÁË£¬ÆøËÀÎÒÁË£¡\n");
}
        return ("ÎÊÊ²Ã´ÎÊ£¡×Ô¼ºÏëÈ¥£¡\n");
}
void init()
{     add_action("do_true", "true");
}

int do_true(string arg)
{
        if(this_player()->query("class") != "sanjie" )
                return 0;
        if(this_player()->query_temp("sj_betray") > 1 ) {
                message_vision("$N´ğµÀ£ºµÜ×Ó½²µÄÕæĞÄ»°£¡\n\n", this_player());
                message_vision("³¯ÑôÌìÊ¦Ì¾ÁË¿ÚÆø£¬¼ÈÊÇÈç´Ë£¬Äã±ãÏÂÉ½°É£¡\n", this_player());
                this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
		this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
		if( this_player()->query_skill("tianmogong") )
		    this_player()->delete_skill("tianmogong");
		if( this_player()->query_skill("huntianforce") )
	            this_player()->delete_skill("huntianforce");
                this_player()->add("betray/count", 1);
                this_player()->add("betray/sanjie", 1);
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "ÆÕÍ¨°ÙĞÕ");
                this_player()->set("faith",0);
                this_player()->set_temp("sj_betray", 0);
                this_player()->save();
                message_vision("³¯ÑôÌìÊ¦Éì³öÊÖ½«$NÒ»ÍÆ£¬$N»¯×÷Ò»¹ÉÇàÑÌÏò¶«¶øÈ¥ ... \n", this_player());
                this_player()->move("/d/sanjie/sanjiedao");
                tell_room( environment(this_player()),"Ìì¿ÕÉÏàÛàÛàÂàÂ¼¸ÉùÏì£¬µôÏÂ¸öÈËÀ´£¡\n", ({this_player()}));
                this_player()->unconcious();            
                return 1;
                }
        return 0;
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="Èı½çÉ½") {
	if ((int)ob->query("daoxing") < 100000 ) {
  	command("say ÄãµÄµÀĞĞ»¹²»¹»£¬" + RANK_D->query_respect(ob) + "»¹Ğè¶à¼ÓÅ¬Á¦¡£\n");
	return;
	}

	if( (int)ob->query("pending/kick_out")) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "ÄãÔø±³ÎÒÅÉ£¬ÎÒ²»Ô­ÔÙÊÕÄãÎªÍ½ÁË£¡\n");
	command("sigh");
	return;
	}

	if ((int)ob->query_int() < 25) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "ÎòĞÔÌ«µÍ£¬¿ÖÅÂÊÕÁËÄãÒ²ÄÑÓĞ×÷Îª£¡\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("tianmogong", 1) < 100 ) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "¶ÔÎÒÌìÄ§¹¦Áì»á»¹²»¹»Éî£¬ÏÖÔÚÊÕÄãÒ²ÊÇÃãÎªÆäÄÑ£¬²»Èç×÷°Õ£¡\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) + "¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓĞ³É¡£");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say ÀÏ·ò²»ÊÕÍâÃÅµÜ×Ó£¬" + RANK_D->query_respect(ob) + "»¹ÊÇÁíÑ°ËûÈË°É£¡\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "sanjie");
}

ÿ
