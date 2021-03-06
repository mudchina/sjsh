// rm.c
//last modified by kissess for log monitoring

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string file)
{
       string filename;
        filename=resolve_path(me->query("cwd"), file);
	seteuid(geteuid(me));
    if (!file) return notify_fail("你要删除那个档案?\n");
	if( rm(resolve_path(me->query("cwd"), file)) )
		write("Ok.\n");
	else
		write("你没有删除这个档案的权利。\n");
log_file("cmds/file/rm",
   sprintf("%s(%s) 删除文件 %s 在 %s\n",me->name(1), geteuid(me), filename, ctime(time()) ) );
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : rm <档名>

此指令可让你删除有权修改的档案。
HELP
    );
    return 1;
}
