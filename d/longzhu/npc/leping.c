// ÀÖÆ½ by Calvin

inherit NPC;
#include <ansi.h>

void create()
{
        set_name(HIW"ÀÖÆ½"NOR, ({"le ping","ping","le"}));
        set("title", HIG"¶àÁÖËÂÑ²Ê¹"NOR);
        set("long", "Ò»Î»¶àÁÖËÂµÄĞ¡Ñ§Í½¡£\n");

        set("gender", "ÄĞĞÔ");
        set("attitude", "peaceful");

        set("age", 19+random(1));
        set("combat_exp", 5000000+random(5000000));
        set("daoxing", 5000000+random(5000000));

        set("shen_type", 1);
        set("per", 25);
        set("max_kee",100000);
        set("max_gin", 100000);
        set("force", 1000);
        set("spells", 1000);
        set("force_factor", 10);
        set_skill("force", 100+random(100));
        set_skill("unarmed",500+random(500));
        set_skill("dodge",500+random(500));
        set_skill("parry", 500+random(500));

        setup();
        carry_object("/d/longzhu/armor/xingtian")->wear();
        carry_object("/d/longzhu/obj/5");
        setup();
}

void die()
{
 int i;
 object me,*inv;
 if(objectp(me=query_temp("last_damage_from") ))
        {
            inv = all_inventory(this_object());
            for(i=0; i<sizeof(inv); i++)
            {
                if (inv[i]->query("id")=="5" || inv[i]->query("id")=="huang longzhu")
                {
                   inv[i]->move(me);
                   message_vision("$NµôÏÂÒ»Ã¶´¿»ÆÉ«µÄÖé×Ó£¬$n¸ÏÃ¦Ò»°Ñ×¥µ½»³Àï¡£\n",this_object(),me);
            message("channel:rumor",HIG+"¡¾"HIW"ÁúÖé´«Ëµ"HIG"¡¿"HIC"ËïÎò¿Õ"HIW"£º¾İËµ"+me->query("name")+"ÔÚ³¤°²³Ç¸½½üµÃµ½ÁË"HIY"»ÆÁúÖé"HIW"¡£\n"+NOR,users());
         }
        }
  }
 ::die();
}

int accept_fight(object me)
{
        command("say ºÃ°É£¬Æö´ê¼¼ÒÕ£¬µãµ½ÎªÖ¹,Èç¹ûÄãÓ®ÁËÎÒ¾Í¸æËßÄãÁúÖéµÄÊÂ£¡\n");
        command("say ÎÒÖ»ÖªµÀÁúÖéµÄÊÂ,ÆäËûÎÒÒ»¸Å²»Öª£¡\n");
        command("say ÎÒ¸æËßÄãÕâ¸öÃØÃÜ,Äã¿É²»ÒªËµÊÇÎÒËµµÄ°¡£¡\n");
        command("say ³¤°²³ÇµÄÄÇ¸ö»¯ÉúËÂÀïµÄÓÎ·½É®ÈËÄÇµ½ÊÇÓĞ¿Å,²»ÖªÊÇÕæÊÇ¼Ù£¡\n");
        command("say ÆäËûµÄÎÒÕæµÄÊ²Ã´Ò²²»ÖªµÀÁË£¡\n");
        return 1;
}
int accept_ask(object me)
{
        command("say ÎÒÖ»ÖªµÀÁúÖéµÄÊÂ,ÆäËûÎÒÒ»¸Å²»Öª£¡\n");
        command("say ÎÒ¸æËßÄãÒ»¸öÃØÃÜ,Äã¿É²»ÒªËµÊÇÎÒËµµÄ°¡£¡\n");
        command("say ³¤°²³ÇµÄÄÇ¸ö»¯ÉúËÂÀïµÄÓÎ·½É®ÈËÄÇµ½ÊÇÓĞ¿Å,²»ÖªÊÇÕæÊÇ¼Ù£¡\n");
        command("say ÆäËûµÄÎÒÕæµÄÊ²Ã´Ò²²»ÖªµÀÁË£¡\n");
        return 1;
}

ÿ
