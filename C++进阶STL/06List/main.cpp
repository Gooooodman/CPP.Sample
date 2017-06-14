#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
/*
 1:��֧���������
    //list<int>::const_iterator itx;
    //itx + 2;//��֧���������
 2:�Զ���Ԫ�ز���ֱ��remove,Ҫ���غ�ſ���
 3:Ԫ�ؿ��ظ�����
 4:ɾ��Ԫ�ػ�ɾ����������������ֵ
 */
class Person
{
public:
    Person(string name, int age)
    {
        this->mName = name;
        this->mAge = age;
    }
    bool operator==(const Person p) const
    {
        if (p.mName == this->mName&&p.mAge == this->mAge)
        {
            return true;
        }
        return false;
    }

public:
    string mName;
    int mAge;
};
class Cmpare
{
public:
    bool operator()(const Person p1, const Person  p2) const
    {
        return p1.mAge < p2.mAge;
    }
};
bool myCompare(const int v1, const int v2)
{
    //�Ӵ�С
    return v1 > v2;
}
void test_foreach(const list<int>& L)
{
    //list<int>::const_iterator itx;
    //itx + 2;//��֧���������
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test_empty_size_resize(list<int>& L)
{
    if (L.empty())
    {
        cout << "Ϊ��" << endl;
    }
    else
    {
        cout << "��Ϊ��  L4 ��С�� " << L.size() << endl;
    }

    L.resize(10);
    L.resize(10, 100);
}
void test_front_front(list<int>& L)
{
    cout << "��һ��Ԫ�أ�" << L.front() << " ���һ��Ԫ�أ� " << L.back() << endl;
    L.pop_back();//βɾ
    L.pop_front();//ͷɾ
    L.push_front(90);
    L.push_back(110);
}
void test_reverse(list<int>& L)
{
    L.reverse();
}

void test01()
{
    list<int> li;
    li.push_back(18);
    li.push_back(12);
    li.push_back(11);
    li.push_back(16);
    li.push_back(13);
    li.push_back(12);

    //li.sort();//Ĭ�ϴ�С����
    //li.sort([](int a, int b) {return a < b; });//��С����
    //li.sort([](int a, int b) {return a > b; });//�Ӵ���
    li.sort(myCompare);
    test_foreach(li);

    for_each(li.begin(), li.end(), [](int a) {cout << a << endl; });

    cout << "�Ƴ�12ǰ��С" << li.size() << endl;
    li.remove(12);
    cout << "�Ƴ�12���С" << li.size() << endl;
}

void test02()
{
    list<Person> lip;
    Person p1("A", 20);
    Person p2("B", 29);
    Person p3("C", 25);
    Person p4("D", 22);
    Person p5("E", 27);
    Person p6("F", 21);
    lip.push_back(p1);
    lip.push_back(p2);
    lip.push_back(p3);
    lip.push_back(p4);
    lip.push_back(p5);
    lip.push_back(p6);

    //�Զ�������������Ҫ���ء�==�������������remove
    lip.remove(p4);

    lip.sort(Cmpare()); //�Զ������Ͳ�֧������

    //lip.sort([](Person p1, Person p2) {return p1.mAge > p2.mAge; });
    for_each(lip.begin(), lip.end(), [](Person p)
    {
        cout << "name��" << p.mName << "��ag��" << p.mAge << endl;
    });
}

int main()
{
    test__Nodeptr();
    system("pause");
    return 0;
}