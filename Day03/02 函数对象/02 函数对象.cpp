#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyPrint
{
public:
    void operator()(int num)
    {
        cout << num << endl;
        count++;
    }
    int count = 0; //ͳ��MyPring���ô���
};

void MyPrint2(int num)
{
    cout << num << endl;
}

void test01()
{
    //�������� �º��� ��һ���࣬�����Ǻ���
    MyPrint myPrint;
    myPrint(100);
}

//�º��� ������ͨ��������ڲ�����ά��һЩ״̬
void test02()
{
    MyPrint myPrint;
    myPrint(100);
    myPrint(100);
    myPrint(100);
    myPrint(100);

    cout << "count = " << myPrint.count << endl;
}

//�º���������Ϊ����
void doWork(MyPrint print, int num)
{
    print(num);
}

void test03()
{
    doWork(MyPrint(), 1000); //MyPrint()
}

int main()
{
    test03();

    system("pause");
    return EXIT_SUCCESS;
}