/*
 * > File Name: ascii.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年06月06日 星期二 16时15分51秒
 *
 *
 * 坑:忘记了ascii表
 *
 * 总结：A为65，a为97，0为48 数字-->大写-->小写
 *
 * 小窍门：将字母转换为全小写/大写，不用判断，直接通过位运算
 *         大写是01000001～01011010（b）
 *         小写是01100001～01111010（b）
 *         直接 或32（d） 来全部转换为小写
 *         直接 与223（d）来全部转换为大写
 *         好像是在王爽的《汇编语言》上看到的
 *
 */

#include <stdio.h>
#include <string.h>
char *my_lower(char *str)
{
    char key = 32; //00100000b
    for(int i = 0; i < strlen(str); i++)
        str[i] |= key;
    return str;
}
char *my_upper(char *str)
{
    char key = 223;//11011111b
    for(int i = 0; i < strlen(str); i++)
        str[i] &= key;
    return str;
}
int main(void)
{
    //char a = 'A', b = 'a',c = '0';
    //printf("%d\n%d\n%d\n",c,a,b);
    char str[20];
    scanf("%s",str);
    printf("%s\n",str);
    printf("all lower %s\n",my_lower(str));
    printf("all upper %s\n",my_upper(str));
}
