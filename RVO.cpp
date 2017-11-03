/*
 * > File Name: RVO.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年10月30日 星期一 22时27分35秒
 */

#include <iostream>
using namespace std;
class A{
    public:
    A() = default;
    A(const A&){cout << "copy construct" << endl;}
    ~A(){cout << "des" << endl;}
};
A f()
{
    /*
    A d = A();
    return d;
    */
    return A();
}
int main(void)
{
    A o = f();
}
