#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <vector>
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

namespace ke
{
    enum
    {
        CAIWU, RENLI, YANFA
    };

    class Worker
    {
    public:
        string mName; //����
        int mMoney; //����
    };

    void createWorker(vector<Worker>&v)
    {
        string nameSeed = "ABCDE";
        for (int i = 0; i < 5; i++)
        {
            string name = "Ա��";
            name += nameSeed[i];

            Worker w;
            w.mName = name;
            w.mMoney = rand() % 10000 + 10000; // 10000 ~ 19999

                                               //��Ա�����뵽������
            v.push_back(w);
        }
    }

    void setGroup(vector<Worker>&v, multimap<int, Worker>&m)
    {
        for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
        {
            //����������ű��
            int departmentId = rand() % 3; // 0 1 2
            //��Ա�����뵽 m������
            m.insert(make_pair(departmentId, *it));
        }
    }

    void showGroup(multimap<int, Worker>&m)
    {
        // 0  A  0  B   1 C   2 D  2 E ������

        cout << "������Ա�����£�" << endl;

        multimap<int, Worker>::iterator pos = m.find(CAIWU);
        int countNum = m.count(CAIWU);
        int num = 0;
        for (; pos != m.end(), num < countNum; pos++, num++)
        {
            cout << "������ " << pos->second.mName << " ���ʣ� " << pos->second.mMoney << endl;
        }

        cout << "-----------------------" << endl;

        cout << "��������Ա�����£�" << endl;

        pos = m.find(RENLI);
        countNum = m.count(RENLI);
        num = 0;
        for (; pos != m.end(), num < countNum; pos++, num++)
        {
            cout << "������ " << pos->second.mName << " ���ʣ� " << pos->second.mMoney << endl;
        }

        cout << "-----------------------" << endl;

        cout << "�з�����Ա�����£�" << endl;
        pos = m.find(YANFA);
        countNum = m.count(YANFA);
        num = 0;
        for (; pos != m.end(), num < countNum; pos++, num++)
        {
            cout << "������ " << pos->second.mName << " ���ʣ� " << pos->second.mMoney << endl;
        }

        cout << "-----------------------" << endl;
    }
    int main()
    {
        //����Ա��
        vector<Worker>v;
        createWorker(v);

        //��Ա�����뵽����������
        //����multimap ��Ų��� �Լ���Ӧ����Ա
        multimap<int, Worker> m;
        setGroup(v, m);

        //�ֲ�����ʾԱ��
        showGroup(m);

        //��������
        /*for (vector<Worker>::iterator it = v.begin(); it != v.end();it++)
        {
        cout << "������ " << it->mName << " ���ʣ� " << it->mMoney << endl;
        }*/

        system("pause");
        return EXIT_SUCCESS;
    }
}

template <typename A, typename B> void print_elem(const pair<A, B>& p)
{
    cout << "(" << p.first << ", " << p.second << ") ";
}

template <typename T> void print_collection(const T& t)
{
    cout << t.size() << " elements: ";

    for (const auto& p : t)
    {
        print_elem(p);
    }
    cout << endl;
}

template <typename C, class T> void findit(const C& c, T val)
{
    cout << "Trying find() on value " << val << endl;
    auto result = c.find(val);
    if (result != c.end())
    {
        cout << "Element found: "; print_elem(*result); cout << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }
}

void test07_multimap()
{
    multimap<int, string> m1({ { 40, "Zr" },{ 45, "Rh" } });
    cout << "The starting multimap m1 is (key, value):" << endl;
    print_collection(m1);

    vector<pair<int, string>> v;
    v.push_back(make_pair(43, "Tc"));
    v.push_back(make_pair(41, "Nb"));
    v.push_back(make_pair(46, "Pd"));
    v.push_back(make_pair(42, "Mo"));
    v.push_back(make_pair(44, "Ru"));
    v.push_back(make_pair(44, "Ru")); // attempt a duplicate

    cout << "Inserting the following vector data into m1:" << endl;
    print_collection(v);

    m1.insert(v.begin(), v.end());

    cout << "The modified multimap m1 is (key, value):" << endl;
    print_collection(m1);
    cout << endl;
    findit(m1, 45);
    findit(m1, 6);
}
int main()
{
    ke::main();

    test07_multimap();

   
    system("pause");
    return 0;
}