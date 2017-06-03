/*
 * > File Name: 返回数组指针的函数指针.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年06月03日 星期六 21时33分32秒
 * 
 *
 *
 * 出处：2+2 & 计科卓越班 2017纳新题
 */

#include <stdio.h>
int (*func(int *a))[5]
{
    int (*p)[5];
    return p;
}
int main(void)
{
    //ptr 是一个函数指针，这个指针指向的类型是 参数为int *，返回值为int (*)[5]
    int (*(*ptr)(int *))[5] = func;

}
