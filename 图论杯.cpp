/*
 * > File Name: 1.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年06月25日 星期日 19时00分44秒
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using  namespace std;
bool IsPalindrome(int num){
    
    int a[100],i =0;
    while(num){
        a[i++] = num%10;
        num = num/10;
    }
    int *p,*q;
    p = &a[0];
    q = &a[i-1];
    while(*p == *q){
        p++;
        q--;
        if(p == q || p > q)
            return true;
    }
    return false;

}
int  NumberOf1(int n)
{
    int i =0;
    while(n){
        i++;
        n = n &(n-1);
    }
    return i;
}
void fun9(int array[],int len)
{
    int *temp = (int *)malloc(sizeof(int)*len);
    int j = 0,k = len - 1;
    for(int i = 0; i < len; i++){
        if(array[i] %2)
            temp[j++] = array[i];
        else
            temp[k--] = array[i];
    }
    for(int i = 0; i < j; i++){
        array[i] = temp[i];
    }
    for(int i = len -1; i > k; i--){
        array[j++] = temp[i];
    }
    for(int i =0; i < len ;i++)
        printf("%d  ",array[i]);
    printf("\n");
    free(temp);
    return ;
}
/*
fun10(struct test *a, struct test *b)
{
    struct test *head,*temp;
    struct test *p = a;
    struct test *q = b;

}
*/
bool checkString(const char *A,const char *B)
{
    const char *p = &B[0];
    const char *q = &A[0];
    while(*p != '\0'){
        while( *q != '\0'&& *p != *q){
            q++; 
        }
        if(*q == '\0')
            return false;
        p++;
        q = &A[0];
    }
    return true;
}
int fun5(char *a)
{
    char *temp = (char *)malloc(sizeof(char) *strlen(a));
    int count = 0,j = 0, k = 0;
    for(int i = 0;i < strlen(a); i++){
        if(a[i] == '*'){
            count++;
        }
        else
            temp[k++] = a[i];
    }
    for(int i = 0; i < count; i++){
        a[i] = '*';
    }
    k = 0;
    for(int i = count; i < strlen(a); i++){
        a[i] = temp[k++];
    }
    free(temp);
    return count;;
}
void Myitoa(char *str, int num, int radix){
    int temp;
    int i = 0;
    while(num){
        temp = num%radix;
        if(temp < 10)
            str[i++] = temp+'0';
        else
            str[i++] =temp + 'a' -10;
        num = num /radix;
    }
    char *t;
    char *p = &str[0];
    char *q = &str[i-1];
    while(p!=q && p < q){
        *t = *p;
        *p = *q;
        *q = *t;
        p++;
        q--;
    }
}
int main(void)
{
    /*第一题
    long long int n;
    scanf("%ld",&n);
    int a[100],i =0;
    while(n){
        a[i++] = n%10;
        n = n/10;
    }
    for(int j = i-1; j>= 0; j--)
        printf("%d,",a[j]);
    */

    /*
    int num;
    scanf("%d",&num);
    if(IsPalindrome(num))
    cout << "true" <<endl;
    else
        cout << "false" << endl;
    */

    /*第八题
    int n;
    scanf("%d",&n);
    printf("%d",NumberOf1(n));
    */
    /*
    int a[4] = {2,1,3,4};
    fun9(a,4);
    */

    /*第六题
    char a[10];
    char b[10];
    scanf("%s",a);
    scanf("%s",b);
    if(checkString(a,b))
    cout << "true";
    else 
        cout << "false";
    */

   /* 第四题
    double n;
    double sum = 0;
    int k = 1;
    for(int i = 1; ; i = i+2){
         n = 1.0 / i;
        if(k%2 == 0)
            n *= -1;
        k++;
        if(1.0/i <= pow(10,-6))
            break;
        else
            sum += n;
    }
    printf("%lf",4*sum);
    */

    /*第五题
    char a[10];
    scanf("%s",a);
    printf("%d",fun5(a));
    */

    /*第七题
    char a[20]={0};
    int num;
    int radix;
    scanf("%d%d",&num,&radix);
    Myitoa(a,num,radix);
    puts(a);
    */
    
}
