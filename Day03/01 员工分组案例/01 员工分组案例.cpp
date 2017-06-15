#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <string>
#include <map>
#include <ctime>

//��˾������Ƹ��5��Ա����5��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
//��Ա��Ϣ��: ���� ���� �绰 ���ʵ����
//ͨ��Multimap������Ϣ�Ĳ��� ���� ��ʾ
//�ֲ�����ʾԱ����Ϣ ��ʾȫ��Ա����Ϣ

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

    int num = 0;
    int countNum = m.count(CAIWU);
    for (; pos != m.end(), num < countNum; pos++, num++)
    {
        cout << "������ " << pos->second.mName << " ���ʣ� " << pos->second.mMoney << endl;
    }

    cout << "-----------------------" << endl;

    cout << "��������Ա�����£�" << endl;
    pos = m.find(RENLI);
    num = 0;
    countNum = m.count(RENLI);
    for (; pos != m.end(), num < countNum; pos++, num++)
    {
        cout << "������ " << pos->second.mName << " ���ʣ� " << pos->second.mMoney << endl;
    }

    cout << "-----------------------" << endl;

    cout << "�з�����Ա�����£�" << endl;
    pos = m.find(YANFA);
    num = 0;
    countNum = m.count(YANFA);
    for (; pos != m.end(), num < countNum; pos++, num++)
    {
        cout << "������ " << pos->second.mName << " ���ʣ� " << pos->second.mMoney << endl;
    }
}

int main() {
    srand((unsigned int)time(NULL));

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