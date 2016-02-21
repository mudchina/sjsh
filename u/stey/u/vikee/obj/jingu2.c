// modified by vikee for xlqy
// 2000-11-28 0:47
// jingu.c ½ô¹¿Öä

#include <ansi.h>

inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name(HIR"½ğ¹¿Öä"NOR, ({ "jingu zhou" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Æª");
        set("long",
        "½ğ¹¿Öä£¬ÓÖ»½×ö¡°¶¨ĞÄÕæÑÔ¡±¡£×²¼ûÉñÍ¨¹ã´óµÄÑıÄ§£¬Ö»ÒÀËùÓÃµÄÖäÓïÄîÒ»Äî£¬¹Ü½ÌËûÈëÎÒÃÅÀ´¡£\n");
        set("material", "paper");       
        }
	setup();
}

void init()
{
	if (this_player() -> query("family/family_name") != "ÄÏº£ÆÕÍÓÉ½" ) {
		remove_call_out("free_jingu");
		call_out("free_jingu", 120, this_object(), this_player()); 
	}

	::init();
}

void free_jingu(object ob, object who)
{
        if(!who || !ob) return;

	if (who -> query("family/family_name") != "ÄÏº£ÆÕÍÓÉ½" ) {
		tell_object(who, HIR"Äã·Â·ğÌıµ½ÓĞÈËËµ£º·Ç·ğÃÅÖĞÈË£¬µÃÖ®ÎŞÓÃ£¬²»ÈçÆúÖ®¡£\n"
			+ "Ëæ×ÅÒ»ÉùÇáÏì£¬½ğ¹¿ÖäÒÑÌÚ¿Õ¶øÈ¥£¬²»ÁôÏÂÒ»Ë¿ºÛ¼£¡£\n\n"NOR);
		destruct(ob);
	}
	else { 
		call_out("free_jingu", 120, ob, who);
	}
	return;
}

Š?