#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <iterator>

/*
copy�㷨 ��������ָ����Χ��Ԫ�ؿ�������һ������
@param beg ������ʼ������
@param end ��������������
@param dest Ŀ����ʼ������
*/
void test01()
{
    vector<int>v1;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(40);
    v1.push_back(30);

    vector<int>v2;
    v2.resize(v1.size());
    copy(v1.begin(), v1.end(), v2.begin());

    //for_each(v2.begin(), v2.end(), [](int v){cout << v << " "; });

    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
}

/*
replace�㷨 ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
@param beg ������ʼ������
@param end ��������������
@param oldvalue ��Ԫ��
@param oldvalue ��Ԫ��
*/
/*
replace_if�㷨 ��������ָ����Χ����������Ԫ���滻Ϊ��Ԫ��
@param beg ������ʼ������
@param end ��������������
@param callback�����ص�����ν��(����Bool���͵ĺ�������)
@param oldvalue ��Ԫ��
*/

class myReplace
{
public:
    bool operator()(int v)
    {
        return v > 4;
    }
};

void test02()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    replace(v.begin(), v.end(), 4, 400);

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    replace_if(v.begin(), v.end(), myReplace(), 4000);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

/*
swap�㷨 ��������������Ԫ��
@param c1����1
@param c2����2
*/

void test03()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>v2;
    v2.push_back(10);
    v2.push_back(30);
    v2.push_back(20);

    swap(v, v2);

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

int main()
{
    //test01();
    //test02();
    test03();
    system("pause");
    return EXIT_SUCCESS;
}