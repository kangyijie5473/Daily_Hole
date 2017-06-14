/*
 * > File Name: Strlen.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年06月14日 星期三 09时04分05秒
 *
 *
 *
 * 递归求解字符串长度：
 * 注意--->++p或者p+1而不是p++
 * 出处：图论杯杨老师
 *
 */
#include <stdio.h>
int Strlen(char *p)
{
    if(p == NULL || *p == '\0')
        return 0;
    else 
        return 1 + Strlen(++p);
}
int main(void)
{
    char str[100];
    scanf("%s",str);
    printf("%d\n",Strlen(str));
}
