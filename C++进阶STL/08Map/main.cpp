#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;
/*
    �����ظ�Ԫ�ز��ᱨ�������ݲ�����ӵ�map������
    []�÷�  �������֤ key���ڣ�������[]���з������ݣ����������һ�����ݵ�
    lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
    upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
    equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
 **/

void test00_insert(map<int, int> &mp)
{
    // call insert(ValTy&&) version
    mp.insert(make_pair(2, 20));
    mp[5] = 50;
    // call insert(const value_type&) version
    mp.insert({ 1, 10 });
    mp.insert(map<int, int>::value_type(4, 40));
    mp.insert(pair<int, int>(3, 30));
    cout << "mp size:" << mp.size() << endl;
}
void test01_empty(map<int, int> &mp)
{
    if (mp.empty())
    {
        cout << "mapΪ��" << endl;
    }
    else
    {
        cout << "map�ǿ�" << endl;
    }
}
void test02_foreach(map<int, int> &mp)
{
    for (map<int, int>::iterator i = mp.begin(); i != mp.end(); i++)
    {
        cout << i->first << " : " << (*i).second << "--------------" << mp[i->first] << endl;
    }
    cout << endl;
}
void test03_clear_erase(map<int, int> &mp)
{
    //mp.clear();//ɾ������Ԫ��
    //mp.erase(3); //ɾ��keyΪ3��Ԫ��
    //mp.erase(mp.begin());//ɾ����һ��Ԫ��
    mp.erase(mp.begin(), mp.end());//��ͷɾ��β
}
void test04_find(map<int, int> &mp, int val)
{
    map<int, int>::iterator pos = mp.find(val);
    if (pos != mp.end())
    {
        cout << "�ҵ���  key = " << (*pos).first << " value = " << (*pos).second << endl;
    }
    else
    {
        cout << "δ�ҵ�" << endl;
    }
}
void test05_cout(map<int, int> &mp)
{
    int num = mp.count(8);
    cout << num << endl;
    if (num)
    {
        cout << "����" << endl;
    }
    else
    {
        cout << "������" << endl;
    }
}
void test06_bound(map<int, int> &m)
{
    //lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
    map<int, int>::iterator it = m.lower_bound(3);
    if (it != m.end())
    {
        cout << "�ҵ� lower_bound key = " << (*it).first << " value = " << (*it).second << endl;
    }

    //upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
    map<int, int>::iterator it2 = m.upper_bound(3);
    if (it2 != m.end())
    {
        cout << "�ҵ� upper_bound key = " << (*it2).first << " value = " << (*it2).second << endl;
    }

    //equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
    pair<map<int, int>::iterator, map<int, int>::iterator> it3 = m.equal_range(3);
    if (it3.first != m.end())
    {
        cout << "�ҵ� equal_range�е�lower_bound key =  " << it3.first->first << " value = " << it3.first->second << endl;
    }

    if (it3.second != m.end())
    {
        cout << "�ҵ� equal_range�е�upper_bound key =  " << it3.second->first << " value = " << it3.second->second << endl;
    }
}

void test01()
{
    map<int, int> mp;
    test00_insert(mp);
    //test02_foreach(mp);
    //test04_find(mp, 6);
    test06_bound(mp);

}

class myCompareMap
{
public:
    bool operator()(const int & v1, const int & v2)const
    {
        return v1 > v2;
    }
};
void test02()
{
    map<int, int, myCompareMap> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(map<int, int>::value_type(3, 30));
    m[4] = 40;
    //����key���Ӵ�С
    for (map<int, int, myCompareMap>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
}
int main()
{
    test02();
    system("pause");
    return 0;
}