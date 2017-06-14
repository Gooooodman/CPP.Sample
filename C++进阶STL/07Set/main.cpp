#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <set>

using namespace std;
/*
1 ��Ԫ�ػ��Զ�ȥ��
2������ظ�Ԫ�ر��벻������������ӳɹ�
3��Ĭ�ϴ�С�������򣬣��÷º��� ָ��������򣩿����شӴ�С����
 */
void test01()
{
    pair<string, int> p1("����1", 19);
    pair<string, int> p2("����2", 25);
    cout << p1.first << p1.second << endl;
    cout << p2.first << p2.second << endl;
    p1.swap(p2);
    cout << p1.first << p1.second << endl;
    cout << p2.first << p2.second << endl;
}

void test_insert(set<int> &s1)
{
    pair< set<int>::iterator, bool > ret = s1.insert(10);
    if (ret.second)
    {
        cout << "����ɹ�" << endl;
    }
    else
    {
        cout << "����ʧ��" << endl;
    }

    ret = s1.insert(10);
    if (ret.second)
    {
        cout << "����ɹ�" << endl;
    }
    else
    {
        cout << "����ʧ��" << endl;
    }

    multiset<int>s2; //�ɹ� ���Բ����ظ���keyֵ
    s2.insert(10);
    s2.insert(10);
}
void test_count(set<int> & se, int delVal)
{
    //����  count ����set���� Ҫô0 Ҫô1
    int num = se.count(delVal);
    cout << delVal << "�ĸ���Ϊ��" << num << endl;
    cout << (num ? "���ҵ�" : "δ���ҵ�") << endl;
}

void test_empty_size(set<int> & se)
{
    if (se.empty())
    {
        cout << "seΪ��" << endl;
    }
    else
    {
        cout << "size = " << se.size() << endl;
    }
}

void test_foreach(const set<int> & se)
{
    for (set<int>::iterator i = se.begin(); i != se.end(); i++)
    {
        cout << *i << "\t";
    }
    cout << endl;
}

void test_foreach(set<int> & se)
{
    for (set<int>::iterator i = se.begin(); i != se.end(); i++)
    {
        cout << *i << "\t";
    }
    cout << endl;
}

void test_bound(set<int> & s1)
{
    //lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
    set<int>::iterator it = s1.lower_bound(30);
    if (it != s1.end())
    {
        cout << "�ҵ���lower_bound��ֵ" << *it << endl;
    }

    //upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
    set<int>::iterator it2 = s1.upper_bound(30);
    if (it2 != s1.end())
    {
        cout << "�ҵ���upper_bound��ֵ" << *it2 << endl;
    }

    //equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
    pair<set<int>::iterator, set<int>::iterator> it3 = s1.equal_range(30);
    if (it3.first != s1.end())
    {
        cout << "�ҵ�equal_range��lower_bound��ֵ��" << *(it3.first) << endl;
    }

    if (it3.second != s1.end())
    {
        cout << "�ҵ�equal_range��upper_bound��ֵ��" << *(it3.second) << endl;
    }
}

void test_find(set<int> & se, int val)
{
    set<int>::iterator pos = se.find(val);
    if (pos != se.end())
    {
        cout << "�ҵ���ֵ Ϊ��" << *pos << endl;
    }
    else
    {
        cout << "δ�ҵ�" << endl;
    }
}

void test_clear_erase(set<int> & se)
{
    //se.clear();//ɾ������Ԫ��
    se.erase(se.begin());//ɾ����һ��Ԫ��
    se.erase(5); //ɾ�����е��ڵ�Ԫ��
    se.erase(se.begin(), se.end());//ɾ������
}

void test02()
{
    set<int> se;
    se.insert(2);
    se.insert(5);
    se.insert(6);
    se.insert(1);
    se.insert(3);
    se.insert(15);
    se.insert(9);
    se.insert(5);
    se.insert(11);
    se.insert(8);
    se.insert(11);
    se.insert(19);
    se.insert(16);

    test_foreach(se);
}

class myCompare
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};
void test03()
{
    set<int, myCompare> s;
    s.insert(2);
    s.insert(7);
    s.insert(1);
    s.insert(6);
    for (set<int, myCompare>::iterator i = s.begin(); i != s.end(); i++)
    {
        cout << *i << endl;
    }
}

class Person
{
public:
    Person(string name, int age)
    {
        this->mName = name;
        this->mAge = age;
    }
public:
    string mName;
    int mAge;
};
class myPersonCompare
{
public:
    bool operator()(const Person &p1, const Person &p2) const
    {
        return p1.mAge > p2.mAge;
    }
};
void test04()
{
    set<Person, myPersonCompare> sp;
    Person p4("үү", 50);
    Person p2("����", 10);
    Person p3("����", 6);
    Person p1("����", 20);

    sp = { p1,p2,p3 };
    sp.insert(p4);

    for (set<Person, myPersonCompare>::iterator i = sp.begin(); i != sp.end(); i++)
    {
        cout << i->mName << "   " << (*i).mAge << endl;
    }
}

int main()
{
    test04();

    system("pause");
    return 0;
}