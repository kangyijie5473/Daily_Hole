#include <iostream>
#include <functional>
#include <string>
using namespace std;
class A{
    public:
        static void setFunc(function<void(int)>);
        void run(){func(0);}
    private:
        static function<void(int)> func;
};
void A::setFunc(function<void(int)> a)
{
    A::func = a;
}
void foo(int a)
{
    cout << a << endl;
}
function<void(int)> A::func = NULL;// private static 变量依然需要类外初始化，这句话很关键！
int main(void)
{
    A::setFunc(foo);
    A a;
    a.run();
}
