// worker.c

inherit NPC;
string try_me(object me);

void create()
{
        set_name("ğ«²»·Ö", ({"bo bufen", "bo"}));
        set("gender", "ÄĞĞÔ" );
        set("age", 33);
        set("long", "Ò»¸öÅÖºõºõµÄµÀÊ¿£¬ÕıÉµºÇºÇµÄ²»ÖªĞ¦Ê²Ã´£®\n");
	set("class", "taoist");
        set("combat_exp", 5000);
	set("daoxing", 10000);

        set("attitude", "friendly");

        set("chat_chance_combat", 50 );
        set("inquiry", ([
"Ğ¦Ê²Ã´": "Ê¦¸¸¸Õ½ÌÎÒÒ»ÕĞÒÆĞĞ»»Î»£¬ÎûÎû£®£®£®\n",
"ÒÆĞĞ»»Î»": "ÌıÊ¦¸¸Ëµ¿ÉÒÔ°ÑÈË´«µ½Ô¶´¦£¬ÄãÏëÊÔÊÔ¿´£¿\n",
"ÊÔÊÔ": (: try_me :),
]) );
        setup();

}
string try_me(object me)
{	me = this_player();
        command ("say ÊÔÊÔÒ²ºÃ£®£®£®");

message_vision("ğ«²»·ÖË«ÊÖÍù$NÍ·ÉÏÒ»°´£¬ÄîÁË¾äÖäÓï£®$NÃÔºıÖ®ÖĞºÃÏó·ÉÁË³öÈ¥£®£®£®\n",
me);
	me->move("/d/lingtai/hill");
	return "¹ÖÁË£¬ÈËÔõÃ´²»¼ûÁË£¿";
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 10);
        set("chat_msg", ({
            (: random_move :)
        }) );
}

ÿ
