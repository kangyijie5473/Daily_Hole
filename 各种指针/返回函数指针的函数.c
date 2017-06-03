/*
 * > File Name: 返回函数指针的函数.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年06月03日 星期六 21时47分07秒
 *
 *
 * 出处： 西邮Linux兴趣小组 2017 纳新题
 */

#include <stdio.h>
#include <string.h>
size_t q(size_t b)
{
    return b;
}
size_t (*p(char *str))(size_t a) //(*p(char *str))肯定是返回指针
                                 //最后面的括号是表示函数
                                 //函数类型和q相同
                                 //括号外面还可以再加* 这时q就应该返回size_t *
{
    printf("%s\n",str);
    return q;
}

int main(void)
{
    char str[] = "XiyouLinuxGroup";
    printf("%lu\n",(p(str))(strlen(str)));
}
