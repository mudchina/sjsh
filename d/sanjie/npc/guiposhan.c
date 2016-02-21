// guiposhan.c ¹íÆÆÉ½

#include <ansi.h>
inherit NPC;

void create()
{
  string str;
  int i = random(5)+1;
  set_name(HIR"¹íÆÆÉ½"NOR, ({"gui poshan","gui"}));
  set("gender", "ÄĞĞÔ");
  set("age", 40*i);
  set("long","¹íÓÄÈı×Ó£¬ÉúĞÔºÃ¶ñ¡£\n");
  set("title", HIC"²ØÊ¬µØ"NOR);
  set("attitude", "aggressive");
  set("combat_exp", 1000000*i);
  set("daoxing", 1000000*i);
  set("per", 40);
  set_skill("parry", 40*i);
  set_skill("unarmed", 40*i);
  set_skill("dodge", 40*i);
  set_skill("blade", 40*i);
  set_skill("fork", 40*i);
  set_skill("mace", 40*i);
  set_skill("spear", 40*i);
  set_skill("sword", 40*i);
  set_skill("whip", 40*i);
  set_skill("axe", 40*i);
  set_skill("hammer", 40*i);
  set_skill("rake", 40*i);
  set_skill("stick", 40*i);
  set_skill("staff", 40*i);
  set_skill("dagger", 40*i);
  set("max_sen",2000*i);
  set("max_gee",2000*i);
  set("max_gin",2000*i);
  set("force",2000*i);
  set("mana",2000*i);
  set("max_force",2000*i);
  set("max_mana",2000*i);
  set("force_factor",20*i);
  setup();
  carry_object("/d/sanjie/obj/jinjia")->wear();
  carry_object("/d/sanjie/obj/qinghong")->wield();
}
ÿ