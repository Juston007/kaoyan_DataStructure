#include "stdio.h"
#include "stdlib.h"

#define ElementType int

#define TRUE    1
#define FALSE   0

typedef struct LNode{
    ElementType data;
    struct LNode *next;
} LinkNode,*LinkList;

void TailInsert(LinkList &L){

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

bool GetElement(LinkList &L,int i, ElementType &e){
    if(i < 0){
        return false;
    }

    int j = 0;
    LinkNode *p = L;
    while(p != NULL && j < i){
        p = p->next;
        j++;
    }

    if(p == NULL){
        return false;
    }

    e = p->data;
    return true;
}

bool InesrtNode(LinkList &L,int i,ElementType e){
    if(i < 0){
        return false;
    }

    int j = 0;
    LinkNode *p = L;
    while(p != NULL && j < i - 1){
        p = p->next;
        j++;
    }

    //如果找不到位序i的前驱结点
    if(p == NULL){
        return false;
    }

    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    if(s == NULL){
        exit(0);
    }

    s->data = e;
    s->next = p->next;
    p->next = s;

    return true;
}

bool DeleteNode(LinkList &L, int i, ElementType &e){
    if(i < 0){
        return false;
    }

    int j = 0;
    LinkNode *p = L;
    while(p != NULL && j < i - 1){
        p = p->next;
        j++;
    }

    //找不到前驱 或者 被删除的结点不存在
    if(p == NULL || p->next == NULL){
        return false;
    }

    LinkNode *deleteNode = p->next;

    e = deleteNode->data;
    p->next = deleteNode->next;

    free(deleteNode);

    return true;
}

void PrintList(LinkList &L)
{
    LinkNode *p = L->next;
    while(p != NULL)
    {
        printf("%3d",p->data);//打印当前结点数据
        p = p->next;//指向下一个结点
    }
    printf("\n");
}

/*
输入3 4 5 6 7 9999一串整数，9999代表结束，通过尾插法新建链表，
查找第二个位置的值并输出，
在2个位置插入99，输出为  3 99  4  5  6  7，
删除第4个位置的值，打印输出为  3 99  4  5  6  7。
*/
int main(){

    LinkList list = NULL;

    TailInsert(list);

    int res;
    GetElement(list,2,res);
    printf("%d\n",res);

    InesrtNode(list,2,99);
    PrintList(list);

    DeleteNode(list,4,res);
    PrintList(list);
   
    return 0;
}