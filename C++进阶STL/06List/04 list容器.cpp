#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <list>
#include <algorithm>
#include <string>

void test01()
{
    list<int> myList;
    for (int i = 0; i < 10; i++) {
        myList.push_back(i);
    }

    list<int>::_Nodeptr node = myList._Myhead->_Next;

    for (int i = 0; i < myList._Mysize * 2; i++) {
        cout << "Node:" << node->_Myval << endl;
        node = node->_Next;
        if (node == myList._Myhead) {
            node = node->_Next;
        }
    }
}

/*
3.6.4.1 list���캯��
list<T> lstT;//list���ò���ģ����ʵ��,�����Ĭ�Ϲ�����ʽ��
list(beg,end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
list(n,elem);//���캯����n��elem����������
list(const list &lst);//�������캯����
3.6.4.2 list����Ԫ�ز����ɾ������
push_back(elem);//������β������һ��Ԫ��
pop_back();//ɾ�����������һ��Ԫ��
push_front(elem);//��������ͷ����һ��Ԫ��
pop_front();//��������ͷ�Ƴ���һ��Ԫ��
insert(pos,elem);//��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
clear();//�Ƴ���������������
erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
remove(elem);//ɾ��������������elemֵƥ���Ԫ�ء�
*/

void printList(const list<int>& L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test02()
{
    list<int>L;
    list<int>L2(10, 10);
    list<int>L3(L2.begin(), L2.end());
    L3.push_back(100);

    //�������
    for (list<int>::iterator it = L3.begin(); it != L3.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //�������
    for (list<int>::reverse_iterator it = L3.rbegin(); it != L3.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    list<int> L4;
    L4.push_back(10);
    L4.push_back(20);
    L4.push_back(30);
    L4.push_front(100);
    L4.push_front(200);
    L4.push_front(300);

    printList(L4); // 300 200 100 10 20 30

    //ͷɾ
    L4.pop_front();
    //βɾ
    L4.pop_back();
    printList(L4); //  200 100 10 20

    //insert ����  ������

    L4.insert(L4.begin(), 1000);
    printList(L4); //  1000 200 100 10 20

    //ɾ�� erase
    L4.erase(L4.begin());
    printList(L4); //   200 100 10 20
    L4.push_back(10);//   200 100 10 20 10

    //remove ɾ��������������elemֵƥ���Ԫ��
    L4.remove(10);
    printList(L4);//   200 100  20
}

/*
3.6.4.3 list��С����
size();//����������Ԫ�صĸ���
empty();//�ж������Ƿ�Ϊ��
resize(num);//����ָ�������ĳ���Ϊnum��
�������䳤������Ĭ��ֵ�����λ�á�
���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(num, elem);//����ָ�������ĳ���Ϊnum��
�������䳤������elemֵ�����λ�á�
���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����

3.6.4.4 list��ֵ����
assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);//��n��elem������ֵ������
list& operator=(const list &lst);//���صȺŲ�����
swap(lst);//��lst�뱾���Ԫ�ػ�����
3.6.4.5 list���ݵĴ�ȡ
front();//���ص�һ��Ԫ�ء�
back();//�������һ��Ԫ�ء�

*/

void test03()
{
    list<int> L4;
    L4.push_back(10);
    L4.push_back(20);
    L4.push_back(30);
    L4.push_front(100);
    L4.push_front(200);
    L4.push_front(300);

    printList(L4); // 300 200 100 10 20 30

    if (L4.empty())
    {
        cout << "Ϊ��" << endl;
    }
    else
    {
        cout << "��Ϊ��  L4 ��С�� " << L4.size() << endl;
    }

    L4.resize(10);
    printList(L4);

    cout << "��һ��Ԫ�أ�" << L4.front() << " ���һ��Ԫ�أ� " << L4.back() << endl;
}

/*
list��ת����
reverse();//��ת��������lst����1,3,5Ԫ�أ����д˷�����lst�Ͱ���5,3,1Ԫ�ء�
sort(); //list����
*/
//ָ���������
bool myCompare(int v1, int v2)
{
    //�Ӵ�С
    return v1 > v2;
}

void test04()
{
    list<int> L4;
    L4.push_back(10);
    L4.push_back(20);
    L4.push_back(30);
    L4.push_front(100);
    L4.push_front(200);
    L4.push_front(300);

    //��ת
    L4.reverse();
    printList(L4);

    //����
    //sort(L4.begin(), L4.end()); //���в�֧��������ʵĵ�������������������ʹ��ϵͳ�ṩ�Ĺ����㷨
    //��֧��������ʵ��������ڲ����ṩ��Ӧ�㷨
    L4.sort();
    printList(L4);

    //�Ӵ�С����
    L4.sort(myCompare);
    printList(L4);
}

//�����Զ����������� �������
class Person
{
public:
    Person(string name, int age, int height)
    {
        this->mName = name;
        this->mAge = age;
        this->mHeight = height;
    }
    //���� == �����
    bool operator== (const Person& p)
    {
        if (this->mAge == p.mAge && this->mName == p.mName && this->mHeight == p.mHeight)
        {
            return true;
        }
        return false;
    }

    string mName;
    int mAge;
    int mHeight; // ���
};

//�����Զ����������ͣ�����ָ���������
bool myCompare2(Person & p1, Person & p2)
{
    if (p1.mAge == p2.mAge)
    {
        return p1.mHeight > p2.mHeight;
    }
    else
    {
        return p1.mAge < p2.mAge;
    }
}
void test05()
{
    list<Person> L;

    Person p1("��ɪ", 18, 180);
    Person p2("槼�", 20, 160);
    Person p3("�ɽ�", 80, 175);
    Person p4("����̫һ", 70, 170);
    Person p5("����", 130, 20);
    Person p6("�����", 130, 10);
    Person p7("����", 130, 30);

    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);
    L.push_back(p7);

    //�������� ��С�������� ,���������ͬ ��߰��� �Ӵ�С����
    L.sort(myCompare2);

    //����
    for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "������ " << it->mName << " ���䣺" << it->mAge << " ��ߣ� " << it->mHeight << endl;
    }

    //ɾ������̫һ
    L.remove(p4);
    cout << endl;

    for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "������ " << it->mName << " ���䣺" << it->mAge << " ��ߣ� " << it->mHeight << endl;
    }
}

int main() {
    //test01();

    //test02();

    //test03();

    //test04();

    test05();

    system("pause");
    return EXIT_SUCCESS;
}