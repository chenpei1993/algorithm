// 单项链表 SingleLinkNodeList
// 程序作用  Programm
//	单项链表的创建，添加，删除，   SingleLinkNodeList create,add,delete
// 作者 陈沛 时间 27-10-016
// Author Chen Pei  Time 27-10-2016


#include <iostream>


using namespace std;

typedef struct _Link_Node{
	char data;
	struct _Link_Node *next;

}LinkNode,*LinkNodePointer;

void CreateSingleLinkNodeList( LinkNodePointer &listpointer){
	char data;
	cin >> data;
	if (data == '#'){
		listpointer = NULL;
	}
	else{
		listpointer = (LinkNodePointer)malloc(sizeof(LinkNode));
		listpointer->data = data;
		CreateSingleLinkNodeList(listpointer->next);
	}

}

void PrintSingleLinkNodeList(LinkNodePointer listpointer){
	if (listpointer != NULL){
		//cout << listpointer->data<<endl; //为什么cout 是乱码
		printf("%c", listpointer->data); 
		PrintSingleLinkNodeList(listpointer->next);
	}
}

void AddSingleLinkNodeList(LinkNodePointer *seclistpointer, LinkNodePointer listpointer, LinkNodePointer addpointer, int n){
	if (n == 0){
		addpointer->next = *seclistpointer;
		*seclistpointer=addpointer;
	}
	else{
		for (int i = 1; i < n; i++){
			listpointer = listpointer->next;
		}
		addpointer->next = listpointer->next;
		listpointer->next = addpointer;

	}
}

void DelSingleLinkNodeList(LinkNodePointer *seclistpointer, LinkNodePointer listpointer, int n){
	if (n == 1){
		*seclistpointer=listpointer->next;
	}
	else{
		for (int i = 2; i < n; i++){
			listpointer = listpointer->next;
		}
		LinkNodePointer delpointer = listpointer->next; //?
		listpointer->next = (listpointer->next)->next;
		free(delpointer);
	}
}

void main(){
	LinkNodePointer listpointer;
	printf("请添加一个链表\n");
	CreateSingleLinkNodeList(listpointer);
	printf("你所创建的链表\n");
	PrintSingleLinkNodeList(listpointer);
	printf("\n");
	LinkNode addstruct = { 'a', NULL };
	AddSingleLinkNodeList(&listpointer,listpointer, &addstruct,2);
	printf("在第二个后面添加元素\n");
	PrintSingleLinkNodeList(listpointer);
	printf("\n");
	DelSingleLinkNodeList(&listpointer, listpointer,2);
	printf("删除第3个元素\n");
	PrintSingleLinkNodeList(listpointer);
	printf("\n");
	system("pause");
}

