// guanjia.c π‹º“

#include <ansi.h>

int random_go(object me, string* dirs);

//int change_tianyi();
//int change_tianyao();
//int change_tianmo();
//int change_cangshi();
//int change_leidao();
string ask_cancel();
int change_mieyao();
int change_menpainame();

int gift();

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(WHT"π‹º“"NOR, ({"guan jia", "master"}));
       set("long", "»˝ΩÁ…Ωµƒπ‹º“£¨≤ª∏……Ê√≈≈…∑◊’˘£¨”⁄ «‘⁄µ∫…œø™¡À“ªº“øÕ’ª°£\n");
       set("title", HIC"»˝ΩÁ…Ω"NOR);
       set("per", 40);
       set("gender", "ƒ––‘");
       set("age", 400);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "¿œ∆Õ»À");
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
	"name"     : "Œ“ «’‚¿Ôµƒ¿œ∞Â£¨ƒ„”– ¬¬£ø\n",
	"here"     : "’‚¿Ô «°∏¿À∂˘µÍ°π£¨ƒ„”––Ë“™ø…“‘Ω¯¿¥◊°◊°µÍ°£\n",
	"»˝ΩÁ…Ω"    : (:change_menpainame:),
/*      "ÃÏ“ªπ¨"   : (:change_tianyi:),
      "ÃÏ—˝π¨"   : (:change_tianyao:),
      "ÃÏƒßπ¨"   : (:change_tianmo:),
      "≤ÿ ¨µÿ"   : (:change_cangshi:),
      "¿◊µ∂√≈"   : (:change_leidao:),
*/      
      "√—˝"     : (:change_mieyao:),
      "cancel": (: ask_cancel :),       
      "¿ÒŒÔ"     : (:gift:),
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
say( name()+"–¶ﬂ‰ﬂ‰µÿÀµµ¿£∫’‚Œª" +RANK_D->query_respect(ob)+ "£¨Ω¯¿¥–™–™Ω≈∞…°£\n");
break;
        }
}
/*
int change_tianyi()
{
object tianyi;
object who=this_player();
message_vision("$N‘⁄’ ±æ…œ≤›≤›º∏± £¨∂‘$nÀµµ¿£∫°∞––¡À£¨ƒ„œ÷‘⁄æÕ «ÃÏ“ªπ¨√≈»À¡À°£°±\n",this_object(),this_player());
who->set("family","»˝ΩÁ…Ω");
who->set("title","°∏¿À∂˘µÍ°π◊°øÕ");
return 1;
}

int change_tianyao()
{
object tianyao;
object who=this_player();
message_vision("$N‘⁄’ ±æ…œ≤›≤›º∏± £¨∂‘$nÀµµ¿£∫°∞––¡À£¨ƒ„œ÷‘⁄æÕ «ÃÏ—˝π¨√≈»À¡À°£°±\n",this_object(),this_player());
who->set("family","»˝ΩÁ…Ω");
who->set("title","°∏¿À∂˘µÍ°π◊°øÕ");
return 1;
}

int change_tianmo()
{
object tianmo;
object who=this_player();
message_vision("$N‘⁄’ ±æ…œ≤›≤›º∏± £¨∂‘$nÀµµ¿£∫°∞––¡À£¨ƒ„œ÷‘⁄æÕ «ÃÏƒßπ¨√≈»À¡À°£°±\n",this_object(),this_player());
who->set("family","»˝ΩÁ…Ω");
who->set("title","°∏¿À∂˘µÍ°π◊°øÕ");
return 1;
}

int change_cangshi()
{
object cangshi;
object who=this_player();
message_vision("$N‘⁄’ ±æ…œ≤›≤›º∏± £¨∂‘$nÀµµ¿£∫°∞––¡À£¨ƒ„œ÷‘⁄æÕ «≤ÿ ¨µÿ√≈»À¡À°£°±\n",this_object(),this_player());
who->set("family","»˝ΩÁ…Ω");
who->set("title","°∏¿À∂˘µÍ°π◊°øÕ");
return 1;
}

int change_leidao()
{
object leidao;
object who=this_player();
message_vision("$N‘⁄’ ±æ…œ≤›≤›º∏± £¨∂‘$nÀµµ¿£∫°∞––¡À£¨ƒ„œ÷‘⁄æÕ «¿◊µ∂√≈√≈»À¡À°£°±\n",this_object(),this_player());
who->set("family","»˝ΩÁ…Ω");
who->set("title","°∏¿À∂˘µÍ°π◊°øÕ");
return 1;
}    
*/


int gift()
{
object sanjie;
object who=this_player();
if (this_player()->query("lucky")==2)
{
message_vision("$N∂‘◊≈$n∫ﬂ¡À“ª…˘°£\n",this_object(),this_player());
command("say ¿ÒŒÔ÷ª”–“ª∑›£°¡Ïπ˝æÕ≤ª∏¯¡À£°");
return 1;
}
message_vision("$N‘⁄∂µ¿ÔÃÕ≥ˆ“ªµ¿∑˚÷‰£¨Õ˘$nÕ∑…œ“ªÃ˘Àµµ¿£∫°∞’‚ «∏¯ƒ„µƒΩ±¿¯°£°±\n",this_object(),this_player());
//who->set("class",sanjie);
//who->set("family","»˝ΩÁ…Ω");
//who->set("title","°∏¿À∂˘µÍ°π◊°øÕ");
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

int change_mieyao()
{
    object who=this_player();
    string family;
    family=who->query("family/family_name");
   switch(family) {
    	case "»˝ΩÁ…Ω":      
        case "ÃÏ“ªπ¨":      
        case "ÃÏ—˝π¨":
        case "ÃÏƒßπ¨":
        case "≤ÿ ¨µÿ":
        case "¿◊µ∂√≈":       
return "/d/obj/mieyao"->query_yao(who);
break;
        default:
         command("heng");
         command("say "+who->query("name")+"∑«Œ“√≈»À,∫Œπ ¿¥¥À? \n");
   //      return 1;
                     } 
}

string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("√ª”√µƒ∂´Œ˜£°");
}
else
{
     return ("ƒ„”–»ŒŒÒ¬£ø£°");
}
}


int change_menpainame()
{
    object who=this_player();
    string family;
    family=who->query("family/family_name");
   switch(family) {
    	case "»˝ΩÁ…Ω":      
           command("say "+who->query("name")+"ƒ„√ª ¬£°πˆ“ª±ﬂ»•£° \n");
             break;
        case "ÃÏ“ªπ¨":      
           who->set("family","»˝ΩÁ…Ω");
           command("say "+who->query("name")+"“—æ≠Õ—Ã•ªªπ«¡À£° \n");
             break;
        case "ÃÏ—˝π¨":
           who->set("family","»˝ΩÁ…Ω");
           command("say "+who->query("name")+"“—æ≠Õ—Ã•ªªπ«¡À£° \n");
             break;
        case "ÃÏƒßπ¨":
           who->set("family","»˝ΩÁ…Ω");
           command("say "+who->query("name")+"“—æ≠Õ—Ã•ªªπ«¡À£° \n");
             break;
        case "≤ÿ ¨µÿ":
           who->set("family","»˝ΩÁ…Ω");
           command("say "+who->query("name")+"“—æ≠Õ—Ã•ªªπ«¡À£° \n");
             break;
        case "¿◊µ∂√≈":       
           who->set("family","»˝ΩÁ…Ω");
           command("say "+who->query("name")+"“—æ≠Õ—Ã•ªªπ«¡À£° \n");
             break;
        default:
         command("heng");
         command("say "+who->query("name")+"∑«Œ“√≈»À,∫Œπ ¿¥¥À? \n");
   //      return 1;
                     } 
}


ˇ
