// guanjia.c ¹Ü¼Ò

#include <ansi.h>

int random_go(object me, string* dirs);

int change_tianyi();
int change_tianyao();
int change_tianmo();
int change_cangshi();
int change_leidao();

int gift();

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(WHT"¹Ü¼Ò"NOR, ({"guan jia", "master"}));
       set("long", "Èý½çÉ½µÄ¹Ü¼Ò£¬²»¸ÉÉæÃÅÅÉ·×Õù£¬ÓÚÊÇÔÚµºÉÏ¿ªÁËÒ»¼Ò¿ÍÕ»¡£\n");
       set("title", HIC"Èý½çÉ½"NOR);
       set("per", 40);
       set("gender", "ÄÐÐÔ");
       set("age", 400);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "ÀÏÆÍÈË");
       set("max_kee", 500);
       set("max_gin", 100);
       set("max_sen", 500);
       set("force", 500);
       set("max_force", 500);
       set("force_factor", 50);
       set("max_mana", 500);
       set("mana", 500);
       set("mana_factor", 50);
       set("combat_exp", 45000);
       set("daoxing", 55000);

	set("inquiry", ([
	"name"     : "ÎÒÊÇÕâÀïµÄÀÏ°å£¬ÄãÓÐÊÂÂð£¿\n",
	"here"     : "ÕâÀïÊÇ¡¸ÀË¶ùµê¡¹£¬ÄãÓÐÐèÒª¿ÉÒÔ½øÀ´×¡×¡µê¡£\n",
	"Èý½çÉ½"   : "ÕâÀï¾ÍÊÇÈý½çÉ½ÁË£¬ÄãÏëÈ¥²»Í¬µÄµØ·½Òª¿´µØÍ¼°¡£¬Èý½çµººÜ´ó°¡¡£\nÈç¹ûÄãÏëµ½Èý½çÉ½²»Í¬µÄÊ¦¸µ£¬¿ÉÒÔÀ´ÎÊÎÒ¡£\nÈý½çÉ½ÓÐ£ºÌìÒ»¹¬¡¢ÌìÑý¹¬¡¢ÌìÄ§¹¬¡¢À×µ¶ÃÅ¡¢²ØÊ¬µØ\nÏëÈ¥ÕÒÊ²Ã´Ê¦¸µ£¬¾ÍÀ´ÎÊÎÊÎÒÀ²¡£",
//	"ÌìÒ»¹¬"   : (:change_tianyi:),
//	"ÌìÑý¹¬"   : (:change_tianyao:),
//	"ÌìÄ§¹¬"   : (:change_tianmo:),
//	"²ØÊ¬µØ"   : (:change_cangshi:),
//	"À×µ¶ÃÅ"   : (:change_leidao:),
	
	"ÀñÎï"   : (:gift:),
	]));
	
	setup();
}

void init()
{
object ob, me;
me=this_object();
::init();
if( interactive(ob = this_player()) && !is_fighting() ) {
remove_call_out("greeting");
call_out("greeting", 1, ob);
}
}

int random_go(object me, string* dirs)
{
int             i, j, k;
object  newob;
mixed*  file;
if( !sizeof(dirs) )  return 1;
i = random(sizeof(dirs));
file = get_dir( dirs[i]+"*.c", -1 );
if( !sizeof(file) )
return 1;
k = sizeof(file);
while(1)  {
j = random(k);
if( file[j][1] > 0 )
break;
}
if( (newob=find_object(dirs[i]+file[j][0])) )   {
me->move( newob ); 
}
else  {
seteuid(getuid(me));
newob = load_object(dirs[i]+file[j][0]);
if (newob)
me->move(newob);
else  {
tell_object(me, "Error.\n");
}
}
return 1;
}

void greeting(object ob)
{
if( !ob || !visible(ob) || environment(ob) != environment() ) 
return;
switch( random(3) ) {
case 0:
say( name()+"Ð¦ßäßäµØËµµÀ£ºÕâÎ»" +RANK_D->query_respect(ob)+ "£¬½øÀ´ÐªÐª½Å°É¡£\n");
break;
        }
}

int change_tianyi()
{
object tianyi;
object who=this_player();
message_vision("$NÔÚÕÊ±¾ÉÏ²Ý²Ý¼¸±Ê£¬¶Ô$nËµµÀ£º¡°ÐÐÁË£¬ÄãÏÖÔÚ¾ÍÊÇÌìÒ»¹¬ÃÅÈËÁË¡£¡±\n",this_object(),this_player());
who->set("family","ÌìÒ»¹¬");
who->set("title","¡¸ÀË¶ùµê¡¹×¡¿Í");
return 1;
}

int change_tianyao()
{
object tianyao;
object who=this_player();
message_vision("$NÔÚÕÊ±¾ÉÏ²Ý²Ý¼¸±Ê£¬¶Ô$nËµµÀ£º¡°ÐÐÁË£¬ÄãÏÖÔÚ¾ÍÊÇÌìÑý¹¬ÃÅÈËÁË¡£¡±\n",this_object(),this_player());
who->set("family","ÌìÑý¹¬");
who->set("title","¡¸ÀË¶ùµê¡¹×¡¿Í");
return 1;
}

int change_tianmo()
{
object tianmo;
object who=this_player();
message_vision("$NÔÚÕÊ±¾ÉÏ²Ý²Ý¼¸±Ê£¬¶Ô$nËµµÀ£º¡°ÐÐÁË£¬ÄãÏÖÔÚ¾ÍÊÇÌìÄ§¹¬ÃÅÈËÁË¡£¡±\n",this_object(),this_player());
who->set("family","ÌìÄ§¹¬");
who->set("title","¡¸ÀË¶ùµê¡¹×¡¿Í");
return 1;
}

int change_cangshi()
{
object cangshi;
object who=this_player();
message_vision("$NÔÚÕÊ±¾ÉÏ²Ý²Ý¼¸±Ê£¬¶Ô$nËµµÀ£º¡°ÐÐÁË£¬ÄãÏÖÔÚ¾ÍÊÇ²ØÊ¬µØÃÅÈËÁË¡£¡±\n",this_object(),this_player());
who->set("family","²ØÊ¬µØ");
who->set("title","¡¸ÀË¶ùµê¡¹×¡¿Í");
return 1;
}

int change_leidao()
{
object leidao;
object who=this_player();
message_vision("$NÔÚÕÊ±¾ÉÏ²Ý²Ý¼¸±Ê£¬¶Ô$nËµµÀ£º¡°ÐÐÁË£¬ÄãÏÖÔÚ¾ÍÊÇÀ×µ¶ÃÅÃÅÈËÁË¡£¡±\n",this_object(),this_player());
who->set("family","À×µ¶ÃÅ");
who->set("title","¡¸ÀË¶ùµê¡¹×¡¿Í");
return 1;
}

int gift()
{
object sanjie;
object who=this_player();
if (this_player()->query("lucky")==2)
{
message_vision("$N¶Ô×Å$nºßÁËÒ»Éù¡£\n",this_object(),this_player());
command("say ÀñÎïÖ»ÓÐÒ»·Ý£¡Áì¹ý¾Í²»¸øÁË£¡");
return 1;
}
message_vision("$NÔÚ¶µÀïÌÍ³öÒ»µÀ·ûÖä£¬Íù$nÍ·ÉÏÒ»ÌùËµµÀ£º¡°ÕâÊÇ¸øÄãµÄ½±Àø¡£¡±\n",this_object(),this_player());
//who->set("class",sanjie);
//who->set("family","Èý½çÉ½");
//who->set("title","¡¸ÀË¶ùµê¡¹×¡¿Í");
who->set_skill("literate",50);
who->set_skill("dodge",50);
who->set_skill("zhaoyangbu",50);
who->set_skill("sword",50);
who->set_skill("huxiaojian",50);
who->set_skill("unarmed",50);
who->set_skill("huxiaoquan",50);
who->set_skill("liushenjue",50);
who->set_skill("stick",50);
who->set_skill("tianyaofa",50);
who->set_skill("force",50);
who->set_skill("huntianforce",50);
who->set_skill("spells",50);
who->set_skill("tianmogong",50);
who->set_skill("blade",50);
who->set_skill("zileidao",50);
who->set_skill("dodge",50);
who->set_skill("zhaoyangbu",50);
who->set_skill("parry",50);
//who->set("maximum_force",3000); 
//who->set("max_force",3000); 
//who->set("force",3000); 
//who->set("maximum_mana",3000); 
//who->set("max_mana",3000); 
//who->set("mana",3000); 
//who->set("combat_exp",1700000); 
//who->set("daoxing",2000000); 
//who->set("sanjie","got");
who->set("lucky",2);
return 1;
}

ÿ
