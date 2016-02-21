#include <ansi.h>

int pk();
int nopk();
int gift();
int back();
int bainiao_jian();
int fengbo_cha();
int lunhui_zhang();

inherit NPC;

void create()
{
  set_name(HIW"×ÔÓÉÅ®Éñ"NOR, ({ "ziyou nushen", "nushen"}));
  set("title", HIC"±¦¼¦Õ¾"NOR);   
  set("long", HIW"\nÒ»Î»½¿ÈáÍò·ÖµÄÅ®×Ó£¬ÁæÀþµØÅ¤¶¯×ÅÑüÖ«¡£\nÊÖ¾Ù×ÔÓÉ»ð°Ñ£¬ÓÐ¹ØÓÚ×ÔÓÉµÄÊÂ£¬¿ÉÒÔÎÊÎÊËý¡£\n"NOR+HIC"\n ask nushen about pk Ñ¡Ôñ£Ð£ËµÄµÀÂ·¡£\n ask nushen about nopk Ñ¡Ôñ£Î£Ï£Ð£ËµÄµÀÂ·¡£\n ask nushen about gift ÄÃÈ¡È¡¾­Íê³É´óÄÖÌì¹¬¹ý¹ØµÄ½±Àø¡£\n ask nushen about back ¶ÔÄãµÄÈËÉúÑ¡ÔñÓÐÒ»´ÎÖØÐÂÑ¡ÔñµÄ»ú»á¡£\n\n"NOR);
  set("gender", "Å®ÐÔ");
  set("age", 16);
  set("attitude", "heroism");
  set("per", 32);
  set("max_kee", 5000);
  set("max_gin", 5000);
  set("max_sen", 5000);
  set("force", 6000);
  set("max_force", 12000);
  set("force_factor", 300);
  set("max_mana", 7000);
  set("mana", 16000);
  set("mana_factor", 350);
  set("combat_exp", 2400000);
  set("daoxing", 6800000);
  set("inquiry", ([
  "name" : "ÎÒ¾ÍÊÇ±¦¼¦Õ¾µÄ×ÔÓÉÅ®Éñ£¬Äã¿ÉÒÔÑ¡Ôñ¡°pk¡±»òÕß¡°nopk¡±À´¾ö¶¨ÄãÒÔºóµÄÈËÉú¡£\n",
  "here" : "Äã¿ÉÒÔÑ¡Ôñ¡°pk¡±»òÕß¡°nopk¡±À´¾ö¶¨ÄãÒÔºóµÄÈËÉú¡£\n",
  "PK"   : (:pk:),
  "pk"   : (:pk:),
  "NOPK" : (:nopk:),
  "nopk" : (:nopk:),
  "NO PK" : (:nopk:),
  "no pk" : (:nopk:),
  "gift" : (:gift:),
  "½±Àø" : (:gift:),
  "back" : (:back:),
  "·´»Ú" : (:back:),
  "°ÙÄñ½£·¨" : (:bainiao_jian:),
  "bainiao-jian" : (:bainiao_jian:),
  "·ç²¨Ê®¶þ²æ" : (:fengbo_cha:),
  "fengbo-cha" : (:fengbo_cha:),
  "lunhui-zhang" : (:lunhui_zhang:),
  "ÂÖ»ØÕÈ" : (:lunhui_zhang:),
  ]));
  setup();
}

int pk()
{
string str;
object who = this_player();
object ob = this_object();
if (this_player()->query("ziyou")=="got")
{
message_vision("×ÔÓÉÅ®Éñ¶Ô×Å$NËµ£º¡°ÄãµÄÈËÉúÒÑ¾­¾ö¶¨ÁË£¬Äã»¹Ïë±ä¸Ä£¿¡±\n",who);
return 1;
}
else
{
str=who->name();
message("channel:chat",HIC"¡¾ÏÉÔµ¡¿×ÔÓÉÅ®Éñ£º"+str+"ÒÑ¾­Ñ¡ÔñÁËPKÕâÌõµÀÂ·£¬Íû´ó¼ÒÖªÕÕ¡£\n"NOR,users());
message("channel:rumor",HIM"¡¾Ò¥ÑÔ¡¿×ÔÓÉÅ®Éñ£º"+str+"ÒÑ¾­Ñ¡ÔñÁËPKÕâÌõµÀÂ·£¬Íû´ó¼ÒÖªÕÕ¡£\n"NOR,users());
message_vision("×ÔÓÉÅ®ÉñÔÚ¾ÙÆð»ð°Ñ£¬Íù$NÍ·ÉÏÇáÇáÒ»°¤£¬¶Ô$NËµ£º¡°ÄãÏÖÔÚÒÑ¾­Ñ¡ÔñÁËPKÕâÌõµÀÂ·£¬ÒÔºóºÃ×ÔÎªÖ®À²¡£¡±\n",who);
who->set("ziyouchoose","pk");
who->set("pk","pk");
who->set("ziyou","got");
return 1;
}
}

int nopk()
{
string str;
object who = this_player();
object ob = this_object();
if (this_player()->query("ziyou")=="got")
{
message_vision("×ÔÓÉÅ®Éñ¶Ô×Å$NËµ£º¡°ÄãµÄÈËÉúÒÑ¾­¾ö¶¨ÁË£¬Äã»¹Ïë±ä¸Ä£¿¡±\n",who);
return 1;
}
else
{
str=who->name();
message("channel:chat",HIC"¡¾ÏÉÔµ¡¿×ÔÓÉÅ®Éñ£º"+str+"ÒÑ¾­Ñ¡ÔñÁËNOPKÕâÌõµÀÂ·£¬´ó¼ÒÒÔºó²»ÒªÔÙÎªÄÑËûÁË¡£\n"NOR,users());
message("channel:rumor",HIM"¡¾Ò¥ÑÔ¡¿×ÔÓÉÅ®Éñ£º"+str+"ÒÑ¾­Ñ¡ÔñÁËNOPKÕâÌõµÀÂ·£¬´ó¼ÒÒÔºó²»ÒªÔÙÎªÄÑËûÁË¡£\n"NOR,users());
message_vision("×ÔÓÉÅ®ÉñÔÚ¾ÙÆð»ð°Ñ£¬Íù$NÍ·ÉÏÇáÇáÒ»°¤£¬¶Ô$NËµ£º¡°ÄãÏÖÔÚÒÑ¾­Ñ¡ÔñÁËNOPKÕâÌõµÀÂ·£¬ÒÔºóÇë¶à°ï±ðÈËµÄÃ¦¡£¡±\n",who);
who->set("ziyouchoose","nopk");
who->set("nopk","nopk");
who->set("ziyou","got");
return 1;
}
}

int gift()
{
string str;
object who = this_player();
object ob = this_object();
if (this_player()->query("ziyougift")=="got")	
{
message_vision("×ÔÓÉÅ®Éñ¶Ô×Å$NËµ£º¡°ÄãÒÑ¾­ÄÃ¹ýÁË£¬×öÈË²»ÒªÌ«Ì°ÐÄºÃ¡£¡±\n",who);
return 1;
}
else
if (this_player()->query("obstacle/number") < 34 )
{
message_vision("×ÔÓÉÅ®Éñ¶Ô×Å$NËµ£º¡°ÄãÎ÷ÌìÈ¡¾­»¹Ã»ÓÐÍê³É£¬Çë¶à¼ÓÅ¬Á¦¡£¡±\n",who);
return 1;
}
else
if (this_player()->query("dntg/number") < 10 )
{
message_vision("×ÔÓÉÅ®Éñ¶Ô×Å$NËµ£º¡°Äã´óÄÖÌì¹¬»¹Ã»ÓÐÍê³É£¬³É¹¦ÔÚÏòÄãÕÐÊÖ°¡¡£¡±\n",who);
return 1;
}
else
{
str=who->name();
message("channel:chat",HIC"¡¾ÏÉÔµ¡¿×ÔÓÉÅ®Éñ£º"+str+"ÒÑ¾­¹ýÎ÷ÌìÈ¡¾­¡¢´óÄÖÌì¹¬µÈÄÑ¹Ø£¬ÌØ´Ë½±Àø¡£\n"NOR,users());
message("channel:rumor",HIM"¡¾Ò¥ÑÔ¡¿×ÔÓÉÅ®Éñ£º"+str+"ÒÑ¾­¹ýÎ÷ÌìÈ¡¾­¡¢´óÄÖÌì¹¬µÈÄÑ¹Ø£¬ÌØ´Ë½±Àø¡£\n"NOR,users());
message_vision("×ÔÓÉÅ®ÉñÔÚ¾ÙÆð»ð°Ñ£¬Íù$NÍ·ÉÏÇáÇáÒ»°¤£¬¶Ô$NËµ£º¡°ÄãÒÑ¾­¹ýÎ÷ÌìÈ¡¾­¡¢´óÄÖÌì¹¬µÈÄÑ¹Ø£¬ÌØ´Ë½±Àø¡£¡±\n\n"HIC"$NµÃµ½20ÍòÎäÑ§¡¢500ÄêµÀÐÐ¡¢3000Á½»Æ½ð¡¢ËùÓÐ»ù±¾ÊôÐÔ¼Ó2µãµÄ½±Àø¡£\n"NOR,who);
who->add("combat_exp", 200000 );
who->add("daoxing", 500000 );
who->add("potential", 100000 );
who->add("balance", 30000000 );
who->add("str", 2 );
who->add("cor", 2 );
who->add("int", 2 );
who->add("spi", 2 );
who->add("cps", 2 );
who->add("per", 2 );
who->add("con", 2 );
who->add("kar", 2 );
who->set("ziyougift", "got" );
return 1;
}
}

int back()
{
string str;
object who = this_player();
object ob = this_object();
if (this_player()->query("ziyouback")=="got")
{
message_vision("×ÔÓÉÅ®Éñ¶Ô×Å$NËµ£º¡°ÄãµÄÈËÉúÒÑ¾­·´»ÚÒ»´ÎÁË£¬×öÈË»¹ÊÇ²»ÒªÌ«·´¸´ÎÞ³£ºÃ£¿¡±\n",who);
return 1;
}
else
{
str=who->name();
message_vision("×ÔÓÉÅ®ÉñÔÚ¾ÙÆð»ð°Ñ£¬Íù$NÍ·ÉÏÇáÇáÒ»°¤£¬¶Ô$NËµ£º¡°ÄãÏÖÔÚÒÑ¾­ÖØÐÂÑ¡ÔñÄãµÄÈËÉúµÀÂ·¡£¡±\n",who);
who->delete("ziyouchoose");
who->delete("ziyou");
who->set("ziyouback","got");
return 1;
}
}

//°ÙÄñ½£·¨
int bainiao_jian()
{
object who = this_player();
if(who->query_skill("bainiao-jian",1)>200&&who->query_skill("bainiao-jian",1)%10==0)
{
tell_object(who,HIW"ºÃ°É£¬ÎªÄãµÄ°ÙÄñ½£·¨×Ô´´¾øÕÐÖØÐÂÆðÒ»¸öÃû×ÖÀ²¡£\n"NOR);
tell_object(who,HIW"Ãû×ÖÎª£º°ÙÄñ½£·¨±ØÉ±¼¼\n"NOR);
(: call_other, __FILE__, "bainiao_jian_name_skill", who:);
}
return 1;
}

void bainiao_jian_name_skill(string arg)
{
   object who = this_player();
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=who->query("skill_bainiao-jian");
   if(!pointerp(m_actions))m_actions=({});

   content=who->query("str")+2*who->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-who->query("spi");
   m_act+=(["dodge" :content]);
   content=-who->query("cps");
   m_act+=(["parry" :content]);
   content=who->query("con")+who->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"´ÌÉË"]);

   msg= "$Nºö·¢×Ô´´¾øÕÐ"HIR"¡¸°ÙÄñ½£·¨±ØÉ±¼¼¡¹"NOR"£¬ÊÖÖÐµÄ$wÈçÀÇËÆ»¢£¬Ö±È¡$nµÄ$l";
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   who->set("skill_bainiao-jian",m_actions);
}

//·ç²¨Ê®¶þ²æ
int fengbo_cha()
{
object who = this_player();
if(who->query_skill("fengbo-cha",1)>200&&who->query_skill("fengbo-cha",1)%10==0)
{
tell_object(who,HIW"ºÃ°É£¬ÎªÄãµÄ·ç²¨Ê®¶þ²æ×Ô´´¾øÕÐÖØÐÂÆðÒ»¸öÃû×ÖÀ²¡£\n"NOR);
tell_object(who,HIW"Ãû×ÖÎª£º·ç²¨Ê®¶þ²æ±ØÉ±¼¼\n"NOR);
(: call_other, __FILE__, "fengbo_cha_name_skill", who:);
}
return 1;
}

void fengbo_cha_name_skill(string arg)
{
   object who = this_player();
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=who->query("skill_fengbo-cha");
   if(!pointerp(m_actions))m_actions=({});

   content=who->query("str")+who->query_skill("unarmed",1)/5;
   m_act+=(["damage":content]);
   content=-who->query("spi");
   m_act+=(["dodge" :content]);
   content=-who->query("cps");
   m_act+=(["parry" :content]);
   content=who->query("con")+who->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"´ÁÉË"]);

   msg= "$Nºö·¢×Ô´´¾øÕÐ"HIR"¡¸·ç²¨Ê®¶þ²æ±ØÉ±¼¼¡¹"NOR"£¬ÊÖÖÐµÄ$wÈçÀÇËÆ»¢£¬Ö±È¡$nµÄ$l";
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   who->set("skill_fengbo-cha",m_actions);
}

//ÂÖ»ØÕÈ
int lunhui_zhang()
{
object who = this_player();
if(who->query_skill("lunhui-zhang",1)>200&&who->query_skill("lunhui-zhang",1)%10==0)
{
tell_object(who,HIW"ºÃ°É£¬ÎªÄãµÄÂÖ»ØÕÈ×Ô´´¾øÕÐÖØÐÂÆðÒ»¸öÃû×ÖÀ²¡£\n"NOR);
tell_object(who,HIW"Ãû×ÖÎª£ºÂÖ»ØÕÈ±ØÉ±¼¼\n"NOR);
(: call_other, __FILE__, "lunhui_zhang_name_skill", who:);
}
return 1;
}

void lunhui_zhang_name_skill(string arg)
{
   object who = this_player();
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=who->query("skill_lunhui-zhang");
   if(!pointerp(m_actions))m_actions=({});

   content=who->query("str")+2*who->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-who->query("spi");
   m_act+=(["dodge" :content]);
   content=-who->query("cps");
   m_act+=(["parry" :content]);
   content=who->query("con")+who->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"ÔÒÉË"]);

   msg= "$Nºö·¢×Ô´´¾øÕÐ"HIR"¡¸ÂÖ»ØÕÈ±ØÉ±¼¼¡¹"NOR"£¬ÊÖÖÐµÄ$wÈçÀÇËÆ»¢£¬Ö±È¡$nµÄ$l";
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   who->set("skill_lunhui-zhang",m_actions);
}

ÿ
