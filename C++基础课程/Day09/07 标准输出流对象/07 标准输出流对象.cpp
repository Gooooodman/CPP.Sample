#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
cout.flush() //ˢ�»�����
cout.put() //�򻺳���д�ַ�
cout.write() //��buffe��дnum���ֽڵ���ǰ������С�
*/

void test01()
{
	//��������ַ�
	cout.put('a').put('b').put('\n');

	//����ַ���
	char buf[] = "hello world!";
	cout.write(buf,strlen(buf));
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}