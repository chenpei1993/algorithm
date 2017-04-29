#include<iostream>
#include<stack>
#include<queue>
using namespace std;

typedef struct BitNode{

	char data;
	struct BitNode *lchild, *rchild;
}BitNode,*BiTree;					//struct BitNode ����BitNode    struct BitNode* ���� BiTree

//struct BitNode* &T;
int CreateBiTree(BiTree &T){
	char data;
	scanf_s("%c",&data);
	if (data == '#'){
		T = NULL;
	}
	else{
		T = (BiTree)malloc(sizeof(BitNode));
		T->data = data;
		CreateBiTree(T->lchild);		//���� �ṹ��ָ��
		CreateBiTree(T->rchild);
	}
	return 0;
}

void Visit(BiTree T){
	if (T->data != '#'){
		printf("%c", T->data);
	}
}


void PreOrder(BiTree T){
	if (T != NULL){
		Visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder(BiTree T){
	if (T != NULL){
		InOrder(T->lchild);
		Visit(T);
		InOrder(T->rchild);
	}
}

void PostOrder(BiTree T){
	if (T != NULL){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		Visit(T);
	}
}
//	ABC##DE#G##F###
int main(){
	BiTree T;
	CreateBiTree(T);
	printf("��������� \n");
	PreOrder(T);
	printf("\n");
	printf("��������� \n");
	InOrder(T);
	printf("\n");
	printf("��������� \n");
	PostOrder(T);
	system("pause");
}