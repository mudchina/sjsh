inherit NPC;

string *names = ({
  "ÇàÔÆÂí",
  "À¶·çµñ",
  "×ÏÀ×Áú",
  "°×Ë®¹ê",
  "ºìÍÁÔé",
  "ºÚÚ¤È®",
  "½ğÇ¬±ª",
  "»ÆÀ¤»¢",
});

void create()
{
  set_name(names[random(sizeof(names))], ({"guai shou", "shou"}));
  set("race", "Ò°ÊŞ");
  set("age", 26);

  set_skill("dodge", 120);
  set("combat_exp", 800000);
  set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°½Å", "áá½Å", "Î²°Í" }) );
  set("verbs", ({ "bite"}));

  set("chat_chance", 1);

  set("ride/msg", "Æï");
  set("ride/dodge", 10+random(6));
  set_temp("apply/attack", 100);
  set_temp("apply/armor", 120);

  setup();
}
