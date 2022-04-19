#include "stdio.h"
#include "stdlib.h"

#define ElementType int

#define TRUE    1
#define FALSE   0

typedef struct LNode{
    ElementType data;
    struct LNode *next;
} LinkNode,*LinkList;

void HeadInsert(LinkList &L){
    L = (LinkNode *)malloc(sizeof(LinkNode));
    if(L == NULL){
        exit(0);
    }

    L->next = NULL;

    int input;
    scanf("%d",&input);
    while(input != 9999){
        LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
        if(s == NULL){
            exit(0);
        }

        s->data = input;

        s->next = L->next;
        L->next = s;

        scanf("%d",&input);
    }
}

void TailInsert(LinkList &L){

    LinkNode *p = L;
    LinkNode *head = L;
    LinkNode *tail = L;
    while(tail->next == NULL){
        tail = tail->next;
    }

    while(p != head){
        LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
        if(s == NULL){
            exit(0);
        }

        s->data = p->data;
        s->next = NULL;

        tail->next = s;
        tail = s;

        LinkNode *d = L->next;
        if(d != NULL){
            L->next = L->next->next;
            free(d);
        }
    }
}

void TailInsert1(LinkList &L){

    L = (LinkNode *)malloc(sizeof(LinkNode));
    if(L == NULL){
        exit(0);
    }

    L->next = NULL;
    LinkNode *tail = L;

    int input;
    scanf("%d",&input);
    while(input != 9999){
        LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
        if(s == NULL){
            exit(0);
        }

        s->data = input;
        s->next = NULL;

        tail->next = s;
        tail = s;
        scanf("%d",&input);
    }
}

void PrintList(LinkList &L)
{
    L=L->next;
    while(L!=NULL)
    {
        printf("%d",L->data);//打印当前结点数据
        L=L->next;//指向下一个结点
        if(L!=NULL)
        {
            printf(" ");
        }
    }
    printf("\n");
}
    /*
    输入3 4 5 6 7 9999一串整数，9999代表结束
    通过头插法新建链表，并输出，通过尾插法新建链表并输出
    */
int main(){

    LinkList list = NULL;

    HeadInsert(list);
    PrintList(list);

    TailInsert1(list);
    PrintList(list);
   
    return 0;
}