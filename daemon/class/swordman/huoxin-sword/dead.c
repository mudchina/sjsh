
#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[31mÚ¤½çÕÙ·µÖ»ÄÜ¶ÔÕ½¶·ÖÐµÄ¶ÔÊÖÊ¹ÓÃ¡£[37m\n");
//             if(me->query("family/family_name")!="½£¿ÍÁªÃË")
//             return notify_fail("[Ú¤½çÕÙ·µ£ÝÖ»ÓÐ½£¿ÍÁªÃËµÜ×Ó²Å¿ÉÒÔÊ¹ÓÃ£¡\n");
    if(me->query("swordman/dead_perform")!=1)
    return notify_fail("Äã»¹Ã»Ñ§»á¡¸Ú¤½çÕÙ·µ¡¹£¡\n");
	if((int) me->query_skill("huoxin-sword",1) < 250)
		return notify_fail("ÄãµÄÉñ¹È»îÐÄÁ÷µÈ¼¶²»¹»£¬ÎÞ·¨Ê¹³öÚ¤½çÕÙ·µ¡£\n");
  if (me->query_temp("dead_busy")) return notify_fail("ÄãÃ»°ì·¨Á¬ÐøÊ¹³öÚ¤½çÕÙ·µ¡£\n");


	message_vision(RED"\n$NÍ»È»²å½£¹éÇÊ£¬ºÃÏóÍü¼ÇÁË$nµÄ´æÔÚÒ»°ã£¬Ò»ÕóÁîÈËÖÏÏ¢
µÄÉ±Æø´Ó$NµÄÉíÉÏ»º»ºÉ¢·¢³öÀ´£¬\n"NOR,me,target);
       me->start_call_out( (: call_other, __FILE__, "kill_him", me, target :), random(5)+5);
	me->start_busy(5);
       me->set_temp("dead_busy",1);
       call_out("remove_effect",6+random(3),me);
	return 1;
}

void kill_him(object me, object target)
{
	string msg;
         string myname=me->name(), npcname=target->name();
	if(me->is_fighting() && 
	environment(me) == environment(target))
	{
msg = RED "\n$NÊ¹³öÁËÉñ¹È»îÐÄÁ÷µÄ×îÖÕ°ÂÒå[Ú¤½çÕÙ·µ]£¬ÆÕÌìÖ®ÏÂÎÞÈË¿ÉÆÆµÄ
±ØÖÐ±ØÉ±µÄÕÐÊ½£¡£¡£¡" ;
msg +=  "\n\nËÆºõ´ø×Å¾ÅÌìÊ®µØËùÓÐ¶ñÄ§µÄ×£¸£Ò»°ã£¬½£ÒÔÃêÊÓÒ»ÇÐµÄ×ËÌ¬´ÌÈëÁË
$nµÄÑÊºí£¬ÏÊÑª¼ýÒ»°ãµÄÅçÉä¶ø³ö£¬Á¬²Ò½Ð¶¼À´²»¼°£¬$n
±ãµ¹ÔÚÁËÑª²´Ö®ÖÐ¡£\n" NOR;

	message_vision(msg, me, target);
	target->die();
       {
	 message("channel:rumor",HIM"¡¾·çÑÔ·çÓï¡¿Ä³ÈË£º"+npcname+"±»"+myname+"ÓÃÉñ¹È»îÐÄÁ÷µÄ×î¸ß°ÂÒå[Ú¤½çÕÙ·µ]Ö±½ÓËÍÈ¥ÁËµØÓü£¬Ê¬ÌåµÄÁ³ÉÏ»¹´ø×Å¹îÒìµÄÐ¦ÈÝ¡£\n"NOR,users());
	 }

	}
	return ;
}
void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("dead_busy");
}

