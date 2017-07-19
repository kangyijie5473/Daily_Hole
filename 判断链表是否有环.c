/*
 * > File Name: loop.c
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月19日 星期三 21时46分19秒
 */

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int id;
    struct Node *next;
};
struct Node *init_list()
{
    struct Node *head,*tail,*new;
    int i = 1;
    while(i != 20){
        new = (struct Node *)malloc(sizeof(struct Node));
        if(i == 1)
            tail =head = new;
        new->id = i;
        tail->next = new;
        tail = new;
        i++;
    }
    tail->next = NULL;
    struct Node *p = head;
    int n =12;
    while(n--){
        p = p->next;
    }
    tail->next = p;
    return head;
}
void print(struct Node *head)
{
    while(head){
        printf("%d\n",head->id);
        head = head->next;
    }
}
void judge(struct Node *head)
{
    int n1 = 0,n2 = 0;
    struct Node *fast = head;
    struct Node *slow = head;
    while(fast != slow || fast == head){
        fast = fast->next->next;
        slow = slow->next;
        n1++;
    }
    fast = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
        n2++;
    }
    printf("n1:%d,n2:%d, obj:%d---%d\n",n1,n2,fast->id,slow->id);
    //      n1 != n2 obj相同说明是入口
}
int main(void)
{
   struct Node *head;
   head = init_list();
   //print(head);
   judge(head);
}
