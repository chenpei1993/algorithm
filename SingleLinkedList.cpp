// �������� SingleLinkNodeList
// ��������  Programm
//	��������Ĵ�������ӣ�ɾ����   SingleLinkNodeList create,add,delete
// ���� ���� ʱ�� 27-10-016
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
		//cout << listpointer->data<<endl; //Ϊʲôcout ������
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
	printf("�����һ������\n");
	CreateSingleLinkNodeList(listpointer);
	printf("��������������\n");
	PrintSingleLinkNodeList(listpointer);
	printf("\n");
	LinkNode addstruct = { 'a', NULL };
	AddSingleLinkNodeList(&listpointer,listpointer, &addstruct,2);
	printf("�ڵڶ����������Ԫ��\n");
	PrintSingleLinkNodeList(listpointer);
	printf("\n");
	DelSingleLinkNodeList(&listpointer, listpointer,2);
	printf("ɾ����3��Ԫ��\n");
	PrintSingleLinkNodeList(listpointer);
	printf("\n");
	system("pause");
}

