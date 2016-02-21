// shushan_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name(" Ò…Ω¡Ù—‘∞Â", ({ "board" }) );
        set("location", "/d/shushan/square.c");
        set("board_id", "shushan_b");
        set("long",     " Ò…Ω¡Ù—‘∞Â°£\n" );
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}
