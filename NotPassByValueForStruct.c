/*************************************************************************
	> File Name: 判断两个链表是否相交.c
	> Author: HowYiAlways
	> Mail: championhengyi@gmail.com
	> Created Time: 2017年11月03日 星期五 09时13分32秒
 ************************************************************************/


#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    struct node *next;
} Node, *pNode;

int bListIntersect(Node list1, Node list2) { // 这里采用了传结构体（值传递），这是一种非常不好的操作。
    pNode p, q;                              // 首先无用的copy大大降低了效率，其次就是很容易错。。。

    p = &list1;
    q = p -> next;
    while(q != NULL) {
        p = q;
        q = q -> next;
    }

    // 一处关键的错误，用意是list1的尾节点(n4)连接list2的头(n5)，但由于传值，导致连接的是那个copy的局部变量。
    // 这个局部变量和n5有相同的next值
    p -> next = &list2;
    // 现在就变成了 node1 -> node2 -> ... node 4 -> *node5*(局部变量) -> node 6 -> node 7 -> NULL
    // 因此如果return时node4->next 不置为NULL的话。。。后果不得而知
    q = p;
    pNode temp = p;
    
    while(q != NULL && q -> next != NULL) {
        p = p -> next;
        q = q -> next -> next;
        if(p == q) {
            temp -> next = NULL;

            return 1;
        }
    }
    //temp -> next = NULL;所以这里必须要断

    return 0;
}

int main() {
    Node n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = NULL;

    n5.next = &n6;
    n6.next = &n7;
    n7.next = NULL;

    n8.next = &n9;
    n9.next = &n10;
    n10.next = &n3;
    
    print(n1);
    printf(bListIntersect(n1, n5) == 1 ? "intersect\n" : "not intersect\n");
    print(n1);
    printf("print End\n");
    printf(bListIntersect(n1, n8) == 1 ? "intersect\n" : "not intersect\n");

    return 0;
}
