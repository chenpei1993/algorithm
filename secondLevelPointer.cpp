#include <iostream>

using namespace std;

int a = 10;
int b = 100;
int *q;

void func(int **p){
	cout << "func: &p = " << &p << " ,p = " << p << " ,*p = " << *p << " ,**p = " << **p << endl;
	*p = &b;
	//&p ȡ����ָ��ĵ�ַ������ָ���ŵ����ݣ���p ����ָ���ַ *p ȡ����ָ���ŵ�ֵ��һ��ָ��ĵ�ַ�� **p ȡһ��ָ���ŵ�ֵ��100����
	cout << "func: &p = " << &p << " ,p = " << p << " ,*p = " << *p << " ,**p = " << **p << endl;
}

int main(){
	cout << "&a = " << &a << "&b = " << &b << "&q = " << &q << endl;
	q = &a;
	cout << "*q = " << *q << " ,q = " << q << "&q = " << &q << endl;
	func(&q);
	cout << "*q = " << *q << ", q = " << q << "&q = " << &q << endl;
	system("pause");
	return 0;
}