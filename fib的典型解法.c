/*
 * > File Name: fib各种.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年06月15日 星期四 21时15分14秒
 *
 * 今天《图论杯》比赛又遇到fib了
 * 总想起3G面试时被fib支配的恐惧
 * 但还是要勇敢面对呀
 *
 */

#include <stdio.h>

/* Answer 1 */
int res[1000];
int fib_recursion_memory(int n)                  //带记忆的递归，需要额外开辟的空间大
{                                                //多次求值有优势
    if(res[n] != 0)                              //时间 O(n)
        return res[n];
    if(n == 1 || n == 2)
        return res[n] = 1;
    else
        return res[n] = fib_recursion_memory(n-1) + fib_recursion_memory(n-2);
}

/* Answer 2 */
int fib_recursion(int n)                         // 最简单的递归，当然最慢在 O( 2^(N/2) ) 和 O(2^N) 之间
{
    if(n == 1 || n == 2){
        return 1;
    }else
        return fib_recursion(n-1) +fib_recursion(n-2);
}

/* Answer 3 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int fib_iteration(int cout,int n, int r1, int r2) // 尾递归，使用迭代的思想来递归 空间 O(n) 时间 O(n)
{
    r1 = r1+ r2;
    swap(&r1,&r2);
    if(cout == n || n == 1)
        return r1;    //即使不把return写在一起，编译器也可以优化为空间O(1)的尾递归，
    else              //因为编译器不会每次保存函数栈的信息，因为相当于只使用了最后一次的值，每次压栈时直接覆盖。
        return  fib_iteration(cout + 1, n, r1,r2); 
}

int main(void)
{
    /* Answer 4 */

    int n ;
    scanf("%d",&n);
    
    int r1  = 1,r2 = 1;  
    for(int i = 2; i <=n; i++){ //循环求解，这种方式求单个fib值 O（n）空间O（1）
        r1 = r1 + r2;
        swap(&r1, &r2);
    }
    
    printf("%d\n",r1);

}
