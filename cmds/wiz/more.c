// more.c
// Modified by island@fyzx

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string file;
        object ob;

        seteuid(geteuid(me));
        if (! arg) return notify_fail("ָ���ʽ : more <����>|<�����> \n");
        file = resolve_path(me->query("cwd"), arg);
        if (file_size(file) < 0)
        {
                ob = present(arg, me);
                if (! ob) ob = present(arg, environment(me));
                if (! ob) return notify_fail("û�����������\n");
                file = base_name(ob) + ".c";
        }

        if (! SECURITY_D->valid_read(file, me, "read"))
                return notify_fail("û�����������\n");

        me->start_more_file(file);
        log_file("cmds/file/more", 
        sprintf("[%s] %s more %s \n",ctime(time()) , geteuid(me), file ) );
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : more <������>

���ָ����������Է�ҳ��ʽ����һ���ļ������ݡ�

see also: cat
HELP );
        return 1;
}
