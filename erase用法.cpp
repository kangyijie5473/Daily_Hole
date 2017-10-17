/*
 * Container 使用 iterator 删除元素的正确用法
 */

#include <iostream>
#include <list>
#include <stack>
#include <cstdio>
using namespace std;
int main(void)
{
    list<int> a;
    for (int i = 0; i< 5; i++)
        a.push_back(i);

    for (auto i = a.begin(); i!= a.end();){
        
        i=a.erase(i);
        printf("^\n");
    }
}
