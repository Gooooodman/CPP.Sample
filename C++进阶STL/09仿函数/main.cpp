#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include <iterator>

using namespace std;

class Person
{
public:
    string mName;
    int mAge;
public:
    Person(string name, int age)
    {
        this->mName = name;
        this->mAge = age;
    }

    bool operator==(const Person&p)
    {
        if (this->mName == p.mName && this->mAge == p.mAge)
        {
            return true;
        }
        return false;
    }
};
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

//void MyPrint2(int num)
//{
//	cout << num << endl;
//}

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
//��Ժν��
class VectorCompareInt
{
public:
    bool operator()(const int a, const int b) const
    {
        return a > b;
    }
};
void test04()
{
    vector <int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);

    sort(v.begin(), v.end(), VectorCompareInt());
    sort(v.begin(), v.end(), [](const int a, const int b) { return a < b; });//lamba ���ʽ��������С����
    for_each(v.begin(), v.end(), [](int val) {cout << val << "\t"; });
}

//�Զ�����������
struct MyStruct
{
    MyStruct(int i) : mInt(i) {}

    bool operator < (const MyStruct & rhs) const
    {
        return mInt < rhs.mInt;
    }
    bool operator > (const MyStruct & rhs) const
    {
        return mInt > rhs.mInt;
    }
    int mInt;
};

void foreach_MyStruct(vector<MyStruct> &strct)
{
    for_each(strct.begin(), strct.end(), [](MyStruct  stru) {cout << stru.mInt << "\t"; });
    cout << endl;
}

void test_sort()
{
    using namespace std;
    vector <MyStruct> v1;

    for (int i = 0; i < 7; i++)
    {
        v1.push_back(MyStruct(rand()));
    }

    foreach_MyStruct(v1);

    //sort(v1.begin(), v1.end(), less<MyStruct>());
    sort(v1.begin(), v1.end(), greater<MyStruct>());

    foreach_MyStruct(v1);
}

//������
//һԪν��
class GradeThan0
{
public:

    bool operator()(int val)
    {
        return val > 20;
    }
};

void test_find()
{
    vector <int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);

    //������ֻ��Ҫ�ṩ���ҵĺ���
    vector<int>::iterator pos1 = find_if(v.begin(), v.end(), [](int a) {return a > 20; });
    vector<int>::iterator pos2 = find_if(v.begin(), v.end(), GradeThan0());
    vector<int>::iterator pos3 = find(v.begin(), v.end(), 20);
    if (pos3 != v.end())
    {
        cout << "�ҵ�ֵ��" << (*pos3) << endl;
    }
    else
    {
        cout << "δ�ҵ�ֵ" << endl;
    }
}

void test_find_if()
{
    vector<Person>v;
    Person p1("aaa", 11);
    Person p2("bbb", 20);
    Person p3("ccc", 31);
    Person p4("ddd", 41);
    Person p5("eee", 51);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    //�Զ���������Ҫ���ز��ܲ���
    vector<Person>::iterator pos = find(v.begin(), v.end(), p3);

    if (pos != v.end())
    {
        cout << "�ҵ���p3 ����Ϊ��" << (*pos).mName << " ���� " << pos->mAge << endl;
    }
    else
    {
        cout << "δ�ҵ�" << endl;
    }
}

class MyCompare03 :public binary_function<Person*, Person*, bool>
{
public:
    bool operator()(Person* p1, Person* p2) const
    {
        if (p1->mName == p2->mName && p1->mAge == p2->mAge)
        {
            return true;
        }
        return false;
    }
};

void test_find_if_p()
{
    vector<Person*> v =
    {
        new Person("A",20),
        new Person("B",21),
        new Person("C",22),
        new Person("D",23),
        new Person("E",24)
    };

    Person * p = new Person("D", 23);
    vector<Person *>::iterator pos = find_if(v.begin(), v.end(), bind2nd(MyCompare03(), p));
    if (pos != v.end())
    {
        cout << "�ҵ�ֵ��" << (*pos)->mName << endl;
    }
    else
    {
        cout << "δ�ҵ�ֵ" << endl;
    }
}

//�ڽ���������  ͷ�ļ���functional
void test05()
{
    negate<int> n;
    cout << n(10) << endl;
}

void test06()
{
    plus<int> p;
    cout << p(123, 456) << endl;
}

void test07()
{
    vector <int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);
    //sort(v.begin(), v.end()); //Ĭ�ϵĴ�С����  _STD sort(_First, _Last, less<>());
    //sort(v.begin(), v.end(), greater<int>()); //�Ӵ�С
    sort(v.begin(), v.end(), less<int>());//Ĭ�ϵĴ�С����
    for_each(v.begin(), v.end(), [](int v) {cout << v << "\t"; });
}

class PrintVectorInt :public binary_function<int, int, void>
{
public:
    void operator()(int val, int start) const
    {
        cout << "val:" << val << "  start:" << start << " sum" << val + start << endl;
    }
};
//��������������
void test09()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //����ʹ�ã�bind2nd
    for_each(v.begin(), v.end(), bind2nd(PrintVectorInt(), 100));

    for_each(v.begin(), v.end(), bind1st(PrintVectorInt(), 100));
}

void MyPrint10(int value, int ano)
{
    cout << value << "\t";
}

void test10()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), bind2nd(ptr_fun(MyPrint10), 100));
}

void test11()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int> vDesc;
    vDesc.resize(v.size());
    transform(v.begin(), v.end(), vDesc.begin(), [](int n) {return n; });
    for_each(v.begin(), v.end(), [](int n) {cout << n << endl; });
    for_each(vDesc.begin(), vDesc.end(), [](int n) {cout << n << endl; });
}

void test_bianary_serarch()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //���ҵı�������������
    bool b = binary_search(v.begin(), v.end(), 9);
    cout << (b ? "�ҵ�" : "δ�ҵ�") << endl;
}

void test_cout()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    int num = count(v.begin(), v.end(), 9);
}

class Cout_if
{
public:
    bool operator()(int a)
    {
        return a > 5;
    }
};

bool cout_if_gt5(int a)
{
    return a > 5;
}
void test_cout_if()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    int num1 = count_if(v.begin(), v.end(), [](int val) {return val > 5; });
    int num2 = count_if(v.begin(), v.end(), Cout_if());
    int num3 = count_if(v.begin(), v.end(), cout_if_gt5);
}

void test_random_shuffle()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), [](int a) {cout << a << "\t"; });
    cout << endl;
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int a) {cout << a << "\t"; });
    cout << endl;
}
void test_merge()
{
    vector<int> v1 = { 1,2,3,4,5 };
    vector<int> v2 = { 6,7,8,9 };

    vector<int> v3;
    v3.resize(v1.size() + v2.size());
    //��������������
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for_each(v3.begin(), v3.end(), [](int a) {cout << a << "\t"; });
    cout << endl;
}
void test_reverse()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), [](int a) {cout << a << "\t"; });
    cout << endl;
    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int a) {cout << a << "\t"; });
    cout << endl;
}

void test_accumulate()
{
    //numeric
    vector<int> v;
    for (int i = 1; i <= 100; i++)
    {
        v.push_back(i);
    }

    int sum = accumulate(v.begin(), v.end(), 0);
    //int sum = accumulate(v.begin(), v.end(), 1000);//6050
    cout << "�ܺ�:" << sum << endl;
}

void test_fill()
{
    vector<int> v;
    v.resize(100);
    for (int i = 1; i <= 100; i++)
    {
        //v.push_back(i);
    }

    fill(v.begin(), v.end(), 123);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, "  "));
}

void test_intersection()
{
    vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
    vector<int> v2 = { 5,6,7,8,9,10,11,12,13 };

    vector<int> v3;
    v3.resize(min(v1.size(), v2.size()));
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

    copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, "  "));
}

void test_union()
{
    vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
    vector<int> v2 = { 5,6,7,8,9,10,11,12,13 };

    vector<int> v3;
    v3.resize(v1.size() + v2.size());
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

    copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, "  "));
}

void test_difference()
{
    vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
    vector<int> v2 = { 5,6,7,8,9,10,11,12,13 };

    vector<int> v3;
    v3.resize(v1.size() + v2.size());
    //set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin()); //1,2,3,4
    set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v3.begin());//11,12,13
    copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, "  "));
}

int main()
{
    test_difference();

    system("pause");
}

//not1 ��һԪ��������ȡ��
//not2 �Զ�Ԫ��������ȡ��
//ptr_fun( )��һ����ͨ�ĺ���ָ������ɺ�������