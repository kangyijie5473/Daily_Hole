/*
 * > File Name: testLai.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年11月08日 星期三 20时27分34秒
 */

#include <iostream>
using namespace std;
void fun(const int &t = 100)   // 这里使用const int &
{                              //用处 1.当有参数传递时通过传引用保证效率和直接修改
    cout << "fun" << t << endl;//     2.当使用默认参数时const int &可以直接绑定右值（const左值引用可以绑定左右值） 
}
int main(void)
{
    int a = 3;
    int b = 4;
    const int * const p = &a;
    const int &tt = a;
    tt = b;
    cout << a << endl;
}
