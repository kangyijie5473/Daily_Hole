/*
 * > File Name: 字符串常量.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年06月06日 星期二 17时18分00秒
 *
 *
 * 坑：对常量字符串做更改GCC没有报warning和error
 *     编译通过，然后直接段错误。。
 *     常量字符串加const限定就好了，编译器就帮你检查了
 */

#include <stdio.h>
int main(void)
{
    //const char *str1 = "hello";
    char *str1 = "hello";
    char str2[20] = "world";
    str1[0] = 'A'; //并不会报错。。。但是如果加const 就报了
    str2[0] = 'a';
    printf("%s\n",str2);
}
