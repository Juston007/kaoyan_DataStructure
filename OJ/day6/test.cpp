#include "stdio.h"
#include "stdlib.h"

#define ElementType int

#define TRUE    1
#define FALSE   0

#define MAX_SIZE    5

//top指向下一个位置
typedef struct {
    ElementType data[MAX_SIZE];
    int top;
} Stack;

//使用一个存储空间来区别队满队空
//rear指向队尾元素的下一个位置
typedef struct {
    ElementType data[MAX_SIZE];
    int front, rear;
} Queue;

void InitStack(Stack &stack){
    stack.top = 0;
}

void InitQueue(Queue &queue){
    queue.front = queue.rear = 0;
}

bool StackEmpty(Stack &stack){
    return stack.top == 0;
}

bool StackFull(Stack &stack){
    return stack.top == MAX_SIZE;
}

bool Push(Stack &stack, ElementType e){
    if(StackFull(stack)){
        return false;
    }

    stack.data[stack.top++] = e;
    return true;
}

bool Pop(Stack &stack, ElementType &e){
    if(StackEmpty(stack)){
        return false;
    }

    e = stack.data[--stack.top];
    return true;
}

bool QueueEmpty(Queue &queue){
    return queue.front == queue.rear;
}

bool QueueFull(Queue &queue){
    return (queue.rear + 1) % MAX_SIZE == queue.front;
}

bool EnQueue(Queue &queue, ElementType e){
    if(QueueFull(queue)){
        printf("false\n");
        return false;
    }

    queue.data[queue.rear] = e;
    queue.rear = (queue.rear + 1) % MAX_SIZE;
    return true;
}

bool DeQueue(Queue &queue, ElementType &e){
    if(QueueEmpty(queue)){
        return false;
    }

    e = queue.data[queue.front];
    queue.front = (queue.front + 1) % MAX_SIZE;
    return true;
}

/*
新建一个栈，
读取标准输入3个整数3 4 5，入栈3 4 5，
依次出栈，打印 5 4 3，

新建循环队列（Maxsize为5），
读取标准输入3 4 5 6 7，
入队7时，队满，打印false，
然后依次出队，输出 3 4 5 6
*/
int main(){

    int num;
    Stack stack;
    Queue queue;

    InitStack(stack);
    InitQueue(queue);


    for(int i = 0;i < 3;i++){
        scanf("%d", &num);
        Push(stack, num);
    }

    for(int i = 0;i < 3;i++){
        Pop(stack, num);
        printf("%2d",num);
    }

    printf("\n");

    for(int i = 0;i < 5;i++){
        scanf("%d", &num);
        EnQueue(queue, num);
    }

    while(!QueueEmpty(queue)){
        DeQueue(queue, num);
        printf("%2d",num);
    }



    return 0;
}