
// shaolin-sword.c¡¾ÉÙÁÖ·üÄ§½£¡¿
//for µÀÊ¿ NPCs, if going to be used by players, need refine. 

#include <ansi.h>

inherit SKILL;
string* skill_head =({
        "$NÒ»ÕĞ",
        "Ö»¼û$N×İÉíÇáÇáÔ¾Æğ,Ò»ÕĞ",
        "$NÊ¹³ö",
        "$NÆ®È»¶ø½ø£¬Ò»Ê½",
        "$N×İÉíÇáÇáÔ¾Æğ,½£¹âÈçÂÖ¼±×ª£¬Ò»ÕĞ",
        "$N°´½£¶ø·¢£¬Ò»ÕĞ",
});

mapping *action = ({
	([	"action":
"$NÎÕ½ôÊÖÖĞ$wÒ»ÕĞ"+BLINK""+BLK"¡¸ÎŞÓ°½£·¨¡¹"NOR"ÖĞµÄ"+BLINK""+HIW"¡¸À´È¥×ÔÈç¡¹"NOR"µãÏò$nµÄ$l,
$nÈ´ÎŞ·¨ÕÒµ½$NµÄÉíÓ°,ĞÄÖĞ´ó¾ª",
		"dodge":		-5,
                "parry":                -10,
		"damage":		10,
		"damage_type":	"´ÌÉË"
	]),
	([	"action":
"$NÒ»ÕĞ"+BLK"¡¸ÎŞÓ°½£·¨¡¹"NOR"ÖĞµÄ"+BLINK""+HIW"¡¸ÈÕÔÂÎŞ¹â¡¹"NOR"£¬ÎŞÊı$wÉÏÏÂ´Ì³ö£¬Ö±Ïò$n±ÆÈ¥,
·Â·ğ½£¹âÕÚ×¡ÁËÌ«Ñô,$nÑÛÇ°Ò»ºÚ",
		"dodge":		-25,
                "parry":                -5,
		"damage":		20,
		"damage_type":	"¸îÉË"
	]),
	([	"action":
"$Nµ­µ­Ò»Ğ¦£¬ÏòÇ°¿çÉÏÒ»²½£¬ÊÖÖĞ$wÊ¹³ö"+BLINK""+BLK"¡¸ÎŞÓ°½£·¨¡¹"NOR"ÖĞµÄ"+BLINK""+HIW"¡¸½£Æø·âºí¡¹"NOR"Ö±´Ì$nµÄºí²¿,
$n±»ÏÅµÄÁ¬ÍË¼¸²½,´ËÊ±ÒÑÎŞ»¹ÊÖÖ®Á¦",
		"dodge":		-10,
                "parry":                -15,
		"damage":		15,
		"damage_type":	"´ÌÉË"
	]),
	([	"action":
"$NĞé»ĞÒ»²½£¬Ê¹³ö"+BLK"¡¸ÎŞÓ°½£·¨¡¹"NOR"ÖĞµÄ"+BLINK""+HIW"¡¸ĞÄ¾³ÈçË®¡¹"NOR"ÊÖÖĞ$wÖ±´Ì$nµÄÒªº¦,
$NÈç´ËÀä¾²Áî$n¾õµÃÆäÖĞÓĞÕ©",
		"dodge":		-20,
                "parry":                -5,
		"damage":		15,
		"damage_type":	"´ÌÉË"
	]),
	([	"action":
"Ö»¼û$NÂÕÆğÊÖÖĞµÄ$w£¬Ê¹³ö"+BLK"¡¸ÎŞÓ°½£·¨¡¹"NOR"ÖĞµÄ"+BLINK""+HIW"¡¸·ğ¹âÆÕÕÕ¡¹"NOR"Íòµã½ğ¹âÖ±Éä$n,
½ğ¹âÕÚ×¡ÁË$nµÄÑÛ¾¦,¿É¼û´ËÕĞÔìÒèÖ®Éî",
		"dodge":		-20,
                "parry":                -20,
		"damage":		15,
		"damage_type":	"´ÌÉË"
	]),
        ([      "action":
"$NÂÕÆğÊÖÖĞµÄ$w£¬Ê¹³ö"+BLK"¡¸ÎŞÓ°½£·¨¡¹"NOR"ÖĞµÄ"+BLINK""+HIW"¡¸·çĞĞÒ¶Âä¡¹"NOR"ÎŞÊı½£¹âÖ±Éä$n,
ËÄÖÜ¶ÙÊ±¹ÎÆğÁË¿ñ·ç,ÖÜÎ§µÄÊ÷Ò¶Óë½£Æø±©ÓêÒ»°ã¾íÏòÕĞ¼ÜÖĞµÄ$n",
                "dodge":                -25,
                "parry":                -5,
                "damage":      		20, 
                "damage_type":  "´ÌÉË"
        ]),
	([      "action":
"$NÊ¹³ö"+BLK"¡¸ÎŞÓ°½£·¨¡¹"NOR"ÖĞµÄ"+BLINK""+HIW"¡¸Éù¶«»÷Î÷¡¹"NOR"£¬ÊÖÖĞ$wÈç¹ÎÆğ¿ñ·çÒ»°ãÉÁË¸²»¶¨£¬
¿´ËÆÃ»ÓĞÎ£»ú,Í»È»½£ÆøºÏÎªÒ»´¦´ÌÏò$n",
                "dodge":                -5,
                "parry":                -10,
                "damage":     		10,
                "damage_type":  "´ÌÉË"
        ]),
           ([      "action":
"$NËæÊÖÊ¹³ö"+BLK"¡¸ÎŞÓ°½£·¨¡¹"NOR"Ö®°ÂÒå"+BLINK""+HIW"¡¸ÎŞÓ°ÎŞ×Ù¡¹"NOR"£¬ÊÖÖĞ$wÈç¹í÷ÈÒ»°ãÆÌÌì¸ÇµØµÄ´ÌÏò$n,
$nÊ¹³ö»ëÉí½éÊõÄÑµ²´ËÕĞ,Î¨ÓĞ³·Éí¶øÍË",
                "dodge":                -25,
                "parry":                -10,
                "damage":     		20,
                "damage_type":  "´ÌÉË"
        ]),
            ([      "action":
"$NÊ¹³ö"+BLK"¡¸ÎŞÓ°½£·¨¡¹"NOR"Ö®×îÖÕ¾ø¼¼"+BLINK""+HIW"¡¸òÔÁú³öË®¡¹"NOR",ÊÖÖĞ$wÓÌÈçòÔÁúÒ»°ã´ÌÏò$n ,
$n·Â·ğ¿´µ½Ò»ÌõòÔÁúÍÑË®¶ø³ö,¶ÙÊ±²»ÖªËù´ë",
                "dodge":                -25,
                "parry":                -10,
                "damage":     		30,
                "damage_type":  "´ÌÉË"
        ]),	
       ([	   "action":
"$NÊ¹Ò»Ê½"+BLK"¡¸´ïÄ¦½£·¨¡¹"NOR"ÖĞ"+BLINK""+HIC"¡¸ÍòÊÂËæÔµÍù¡¹"NOR"£¬ÊÖÖĞ$wÎËÎËÎ¢Õñ£¬»Ã³ÉÒ»Ìõ¼²¹â´ÌÏò$nµÄ$l",

		"dodge":		-5,
                "parry":                -10,
		"damage":		10,
		"damage_type":	"´ÌÉË"
	]),
	([	"action":
"$N´í²½ÉÏÇ°£¬Ê¹³ö"+BLK"¡¸´ïÄ¦½£·¨¡¹"NOR"ÖĞ"+BLINK""+HIC"¡¸À´È¥ÈôÃÎĞĞ¡¹"NOR"£¬½£ÒâÈôÓĞÈôÎŞ£¬$wµ­µ­µØÏò$nµÄ$l»ÓÈ¥",
		"dodge":		-25,
                "parry":                -5,
		"damage":		20,
		"damage_type":	"¸îÉË"
	]),
	([	"action":
"$Nµ­µ­Ò»Ğ¦£¬Ò»Ê½"+BLK"¡¸´ïÄ¦½£·¨¡¹"NOR"ÖĞ"+BLINK""+HIC"¡¸¸¡ÊÀ²×É£Ô¶¡¹"NOR"£¬×İÉíÆ®¿ªÊı³ßÔË·¢½£Æø£¬ÊÖÖĞ$wÒ£Ò¡Ö¸Ïò$nµÄ$l",
		"dodge":		-10,
                "parry":                -15,
		"damage":		15,
		"damage_type":	"´ÌÉË"
	]),
	([	"action":
"$N×İÉíÇáÇáÔ¾Æğ£¬Ò»Ê½"+BLK"¡¸´ïÄ¦½£·¨¡¹"NOR"ÖĞ"+BLINK""+HIC"¡¸ÂÖ»Ø·¨ÖÛÇá¡¹"NOR"£¬½£¹âÈçÂÖ¼²×ª£¬»ô»ôÕ¶Ïò$nµÄ$l",

		"dodge":		-20,
                "parry":                -5,
		"damage":		15,
		"damage_type":	"´ÌÉË"
	]),
	([	"action":
"$NÊÖÖĞ$wÖĞ¹¬Ö±½ø£¬Ò»Ê½"+BLK"¡¸´ïÄ¦½£·¨¡¹"NOR"ÖĞ"+BLINK""+HIC"¡¸Ë®ÔÂÍ¨ìø¼Å¡¹"NOR"£¬ÎŞÉùÎŞÏ¢µØ¶Ô×¼$nµÄ$l´Ì³öÒ»½£",
		"dodge":		-20,
                "parry":                -20,
		"damage":		15,
		"damage_type":	"´ÌÉË"
	]),
        ([      "action":
"$NÊÖÖĞ$wĞ±Ö¸²ÔÌì£¬½£Ã¢ÍÌÍÂ£¬Ò»Ê½"+BLK"¡¸´ïÄ¦½£·¨¡¹"NOR"ÖĞµÄ"+BLINK""+HIC"¡¸ÓãÁúÌıèóÒô¡¹"NOR"£¬¶Ô×¼$nµÄ$lĞ±Ğ±»÷³ö",

                "dodge":                -25,
                "parry":                -5,
                "damage":      		20, 
                "damage_type":  "´ÌÉË"
        ]),
	([      "action":
"$N×óÖ¸Áè¿ÕĞéµã£¬ÓÒÊÖ$w±Æ³öÕÉĞíÑ©ÁÁ½£Ã¢£¬Ò»Ê½"+BLK"¡¸´ïÄ¦½£·¨¡¹"NOR"ÖĞ"+BLINK""+HIC"¡¸Ç§ÀïÒ»Î­È¥¡¹"NOR"´ÌÏò$nµÄ$l", 
               "dodge":                -5,
                "parry":                -10,
                "damage":     		10,
                "damage_type":  "´ÌÉË"
        ]),
           ([      "action":
"$NºÏÕÆµø×ø£¬Ò»Ê½"+BLK"¡¸´ïÄ¦½£·¨¡¹"NOR"ÖĞ"+BLINK""+HIC"¡¸ìøĞÄ¶Ù×ÔÃ÷¡¹"NOR"£¬$w×Ô»³ÖĞÔ¾³ö£¬Èç¼²µç°ãÉäÏò$nµÄĞØ¿Ú",
                "dodge":                -5,
                "parry":                -10,
                "damage":     		10,
                "damage_type":  "´ÌÉË"
        ]),
          ([      "action":
"$NÊÕ½£ÔËÆø,½«"+BLK"¡¸ÎŞÓ°½£·¨¡¹"NOR"ºÍ"+BLK"¡¸´ïÄ¦½£·¨¡¹"NOR"»ëÈ»Ò»Ìå,Ê¹³öË«½£ºÏÒ»"+BLINK""+HIY"¡¸´Èº½ÆÕ¶É¡¹"NOR"Ê½£¬
$wÈç·ÉÁú°ã×ÔÕÆÖĞÔ¾³ö£¬Ö±Ïò$nµÄĞØ¿Ú´©Èë¡£",
                "dodge":                -35,
                "parry":                -10,
                "damage":     		40,
                "damage_type":  "´ÌÉË"
        ]),

});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»£¬Ã»ÓĞ°ì·¨Á·ÉÙÁÖ·üÄ§½£¡£\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("Äã±ØĞëÏÈÕÒÒ»°Ñ½£²ÅÄÜÁ·½£·¨¡£\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("ÄãµÄÄÚÁ¦»òÆø²»¹»£¬Ã»ÓĞ°ì·¨Á·Ï°ÉÙÁÖ·üÄ§½£¡£\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("Äã°´×ÅËùÑ§Á·ÁËÒ»±éÉÙÁÖ·üÄ§½£¡£\n");
	return 1;
}
string perform_action_file(string action)
{
  return CLASS_D("shaolin") + "/shaolin-sword/" + action;
}
