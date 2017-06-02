#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
    Person(int a, int b)
    {
        mA = a;
        mB = b;
    }
public:
    int mA;
    int mB;
};

void test01()
{
    Person p1(100, 200);
    Person p2(p1);
    Person p3 = p1;

    cout << "A = " << p2.mA << " B:" << p2.mB << endl;
}

class Student
{
public:
    Student(const char *str, int age)
    {
        pName = (char *)malloc(sizeof(char)* strlen(str) + 1);
        strcpy(pName, str);
        mAge = age;
    }

    Student(const Student &stu)
    {
        //�ֶ����ƿ�������
        cout << "�Զ���Ŀ������캯��!" << endl;
        pName = (char *)malloc(sizeof(char)* strlen(stu.pName) + 1);
        strcpy(pName, stu.pName);
        mAge = stu.mAge;
    }

    ~Student()
    {
        if (pName != NULL)
        {
            free(pName);
            pName = NULL;
        }
    }

public:
    char *pName;
    int mAge;
};

void test02()
{
    //���
    Student s1("trump", 88);
    Student s2(s1);
}

//�������ڲ���ָ��ָ����ڴ棬��ô�����ֶ��ṩ�������캯��
//�������ڲ���ָ��ָ����ڴ棬��ô��ʱ���ֻ�ǵ���Ĭ�ϵĿ������캯�������м򵥵�ָ��ֵ����������ǳ����
//�����д�Զ��忽�����̣����ڴ���п������������

int main()
{
    test02();

    system("pause");
    return EXIT_SUCCESS;
}