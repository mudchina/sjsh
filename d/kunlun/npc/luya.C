
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("Â½Ñ¹", ({"luya","lu","ya"}));
        set("gender", "ÄÐÐÔ" );
        create_family("À¥ÂØÉ½ÓñÐé¶´", 3, "µÜ×Ó");
        set("title",HIG"À¥ÂØÉ½ÓñÐé¶´¹Ü¼Ò"NOR);
        set("age", 41);
       set("class", "xian");
        set("long", "À¥ÂØÉ½ÓñÐé¶´É¢ÏÉÂ½Ñ¹£¬ÔÚ¶´ÖÐ¼æÈÎ¹Ü¼ÒÖ®Ö°¡£\n");
        set("combat_exp", 30);
        set("attitude", "peaceful");
        setup();
  carry_object("/d/obj/cloth/linen")->wear();;
}

