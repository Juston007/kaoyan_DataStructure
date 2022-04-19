#include "stdio.h"
#include "stdlib.h"

#define INIT_SIZE   10
#define ElementType int

#define TRUE    1
#define FALSE   0

typedef struct LNode{
    ElementType *data;
    int length;
    int MaxSize;
} SqList;

bool IncreaseCapacity(SqList &list){
    return true;
}

bool InitList(SqList &list){
    list.data = (ElementType *)calloc(INIT_SIZE, sizeof(ElementType));
    if(list.data == NULL){
        exit(0);
    }
    
    list.MaxSize = INIT_SIZE;
    list.length = 0;
    return true;
}

bool isEmpty(SqList &list){
    return list.length == 0;
}

bool ListInsert(SqList &list,int i,ElementType e){
    //i∈[1,length+1]
    if(!(i >= 1 && i <= list.length + 1)){
        return false;
    }

    //[i-1,length]
    //下标i之后的元素全部后移
    int length = list.length;
    for(int index = length;index >= i;index--){
        list.data[index] = list.data[index - 1];
    }

    list.data[i - 1] = e;
    list.length++;
    return true;
}

bool ListDelete(SqList &list,int i,ElementType &e){
    //i∈[1,length]
    if(!(i >= 1 && i <= list.length)){
        return false;
    }

    int length = list.length;
    for(int index = i;index < length;index++){
        list.data[index - 1] = list.data[index];
    }

    e = list.data[i - 1];
    list.length--;
    return true;
}

void PrintList(SqList &list){
    for(int i = 0;i < list.length;i++){
        printf("%3d",list.data[i]);
    }
    printf("\n");
}

/*
初始化顺序表（顺序表中元素为整型），里边的元素是1,2,3
然后通过scanf读取一个元素（假如插入的是6），插入到第2个位置
打印输出顺序表，每个元素占3个空格
格式为1  6  2  3，然后scanf读取一个整型数
是删除的位置（假如输入为1），然后输出顺序表  6  2  3
假如输入的位置不合法，输出false字符串。提醒，Language一定要选为C++。
*/

int main(){
    SqList list;
    InitList(list);

    ListInsert(list,1,1);
    ListInsert(list,2,2);
    ListInsert(list,3,3);

    int value;
    scanf("%d",&value);

    int index;
    scanf("%d",&index);

    ListInsert(list,2,value);
    PrintList(list);

    if(!ListDelete(list,index,value)){
        printf("false");
    }else{
        PrintList(list);
    }


    return 0;
}