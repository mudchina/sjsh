// Cmds:/cmds/wiz/edsong.c
// Written by jjgod@FYTX.

#include <ansi.h>
inherit F_CLEAN_UP;
string replace_color(string arg,int flag);
int main(object me, string arg)
{
mapping song;
string newsong;
string *editid;
editid=({"buwawa","lovemy","ferser","yingying","lianer","xflower","cartone","trhy","xhuowu","hawks"});
if(!wizardp(me)&&member_array(me->query("id"), editid) ==-1)
return notify_fail("只有巫师或者文人雅士才有资格填词！\n");
if( !arg ) return notify_fail("你要编辑什么乐曲？\n");

if( sscanf(arg, "-c %s %s", arg, newsong) ) {
        if(!wizardp(me)) return notify_fail("你只能添加曲谱！\n");
write("拷贝乐曲：" + arg + "\n");
MUSIC_D->set_song(newsong, MUSIC_D->query_song(arg));
return 1;
}

if( sscanf(arg, "-d %s", arg) ) {
        if(!wizardp(me)) return notify_fail("你只能添加曲谱！\n");
write("删除乐曲：" + arg + "\n");
MUSIC_D->delete_song(arg);
return 1;
}

if( sscanf(arg, "-p %s", arg) ) {
song = MUSIC_D->query_song(arg);
printf("\n作者：%-10s\n题目：%s\n",song["author"],song["name"]);
printf("内容：\n%s\n",song["song"]);
return 1;
}
song=([]);
write("这个乐曲的作者：");
input_to("get_author",me,arg,song);
return 1;
}

void get_author(string author,object me,string id,mapping song)
{
if (author==""||author==".") {
song["author"]="无名氏";
}
else {
song["author"]=author;
}
write("这个乐曲的题目：");
input_to("get_name",me,id,song);
return;
}

void get_name(string name,object me,string id,mapping song)
{
if (name==""||name==".") {
song["name"]="不详";
}
else {
song["name"]=name;
}
write("这个乐曲的内容：\n");
me->edit((: call_other, __FILE__, "get_context", me,id,song:));
return;
}

void get_context(object me,string id,mapping song,string context)
{
if (context==""||context==".") {
song["song"]="我也不知道我在奏些什么呀。";
}
else {
song["song"]=context;
}
write("这个乐曲的采用的颜色（可以有多个，用“,”分隔）：");
input_to("get_color",me,id,song);
return;
}

void get_color(string color,object me,string id,mapping song)
{
string *colors;

if (color==""||color==".") {
// 默认的颜色
song["color"]=({CYN,WHT});
}
else {
color=replace_color(color,1);
color=replace_string(color,NOR,"");
colors=explode(color,",");
song["color"]=colors;
}
MUSIC_D->set_song(id, song);
write("新乐曲 "HIW+id+NOR" 编辑完毕。\n");
return;
}
string replace_color(string arg,int flag)
{
        arg = replace_string(arg, "$BLK$", flag?BLK:"");
        arg = replace_string(arg, "$RED$", flag?RED:"");
        arg = replace_string(arg, "$GRN$", flag?GRN:"");
        arg = replace_string(arg, "$YEL$", flag?YEL:"");
        arg = replace_string(arg, "$BLU$", flag?BLU:"");
        arg = replace_string(arg, "$MAG$", flag?MAG:"");
        arg = replace_string(arg, "$CYN$", flag?CYN:"");
        arg = replace_string(arg, "$WHT$", flag?WHT:"");
        arg = replace_string(arg, "$HIR$", flag?HIR:"");
        arg = replace_string(arg, "$HIG$", flag?HIG:"");
        arg = replace_string(arg, "$HIY$", flag?HIY:"");
        arg = replace_string(arg, "$HIB$", flag?HIB:"");
        arg = replace_string(arg, "$HIM$", flag?HIM:"");
        arg = replace_string(arg, "$HIC$", flag?HIC:"");
        arg = replace_string(arg, "$HIW$", flag?HIW:"");
        arg = replace_string(arg, "$NOR$", flag?NOR:"");
        arg = replace_string(arg, "$BLINK$", flag?BLINK:"");
        if(flag) arg+=NOR;
        return arg;
}

int help(object me)
{
write(@HELP
指令格式：edsong [-c|-d|-p] <song>
 
这个指令可以修改，删除乐曲或列出其内容。加上 -d 参数会删除
指定的乐曲， -p 参数则会列出指定乐曲的内容。列出的顺序与编
辑乐曲时相同。
 
一个乐曲讯息可以有很多行，在空白行输入'.' 结束输入该项乐曲。

HELP
    );
    return 1;
}
