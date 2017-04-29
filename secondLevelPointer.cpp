#include <iostream>

using namespace std;

int a = 10;
int b = 100;
int *q;

void func(int **p){
	cout << "func: &p = " << &p << " ,p = " << p << " ,*p = " << *p << " ,**p = " << **p << endl;
	*p = &b;
	//&p 取二级指针的地址（三级指针存放的内容），p 二级指针地址 *p 取二级指针存放的值（一级指针的地址） **p 取一级指针存放的值（100），
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