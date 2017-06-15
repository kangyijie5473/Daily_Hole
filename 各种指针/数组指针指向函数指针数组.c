/*
 * > File Name: 1.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年06月15日 星期四 23时34分41秒
 *
 * 出处 图论杯
 */

#include <stdio.h>
int fun()
{
    return 1;
}
int main(void)
{
    int (*pp[1])() = {fun}; // 函数指针数组pp 元素是函数指针 函数类型同fun
    int (*(*p)[1])() = &pp; // 数组指针p 指向pp
}
