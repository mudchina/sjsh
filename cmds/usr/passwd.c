// passwd.c

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string arg)
{
        object ob;

        if( me != this_player(1) ) return 0;

        ob = me->query_temp("link_ob");
        if( !ob ) return 0;
        while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

write(HIR"为了安全起见，请先输入您管理密码："NOR);
        input_to("get_old_pass", 1, ob);
        return 1;
}

private void get_old_pass(string pass, object ob)
{
        string old_pass;
 
        write("\n");
        old_pass = ob->query("ad_password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write("密码错误！\n");
                return;
        }
        write("请输入新的密码：");
        input_to("get_new_pass", 1, ob );
}

private void get_new_pass(string pass, object ob)
{
     string ad_pass;
     string my_pass;
     ad_pass = ob->query("ad_password");
     my_pass = ob->query("password");
   if (stringp(ad_pass) && crypt(pass, ad_pass) == ad_pass)
        {
           write(HIR "为了安全起见，系统要求普通密码的密码和管理密码不能相同。\n\n" NOR);
              write("请重新输入你的普通密码：");
              input_to("get_new_pass", 1, ob);
                return;
}
        write("\n请再输入一次新的密码：");
        input_to("confirm_new_pass", 1, ob, crypt(pass,0));
}

private void confirm_new_pass(string pass, object ob, string new_pass)
{
        write("\n");
        if( crypt(pass, new_pass)!=new_pass ) {
                write("对不起，您输入的密码并不相同，继续使用原来的密码。\n");
                return;
        }
        seteuid(getuid());
        if( !ob->set("password", new_pass) ) {
                write("密码变更失败！\n");
                return;
        }
        ob->save();
        write("密码变更成功。\n");
}

int help(object me)
{
        write(@HELP
指令格式 : passwd
 
这个指令可以修改你的人物密码。
 
HELP
    );
    return 1;
}
