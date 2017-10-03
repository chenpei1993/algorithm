#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//    定义一个节点的结构
typedef struct node
{
    int member;            //数据域
    struct node * pNext;//指针域
}Node,*pNode;

//    定义一个栈结构
typedef struct stack
{
    pNode Top;            //栈顶
    pNode Bottom;        //栈底
}Stack,* pStack;



void InitStack(pStack ps)
{
    ps->Top = (pNode)malloc(sizeof(Node));        //    分配内存空间给栈顶
    if (NULL == ps->Top)
    {
        printf("动态分配内存失败\n");
        exit(-1);
    }
    else
    {
        ps->Bottom = ps->Top;                    //    使栈底也指向栈顶空间
        ps->Top->pNext = NULL;                    //    栈顶指针置为NULL；
    }
    return ;
}

//    进行进栈操作的函数
bool Push(pStack ps,int data)
{
    pNode pNew = (pNode)malloc(sizeof(Node));    //    定义一个新节点，并分配内存空间
    if (NULL == pNew)
    {
        return false;
    }
    pNew->member = data;                        //    把要进栈的数据赋给新节点的member成员
    pNew->pNext = ps->Top;                        //    使新节点的指针指向栈顶
    ps->Top = pNew;                                //    把新节点作为新栈顶

    return true;
}

//    遍历栈的函数
void TraverseStack(pStack ps)
{
    pNode pNew = ps->Top;
    while(pNew!= ps->Bottom)                //    只要栈顶不等于栈底，循环
    {
        printf("%d ",pNew->member);            //    打印栈顶的成员member
        pNew = pNew->pNext;                //    栈顶指针向下移动一次
    }
    return ;
}
