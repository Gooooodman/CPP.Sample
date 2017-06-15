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

void showGroup1(multimap<int, Worker>&m)
{
    // 0  A  0  B   1 C   2 D  2 E ������

    multimap<int, Worker>::iterator cPos = m.find(CAIWU);
    multimap<int, Worker>::iterator rPos = m.find(RENLI);
    multimap<int, Worker>::iterator yPos = m.find(YANFA);

    int cNum = m.count(CAIWU);
    int rNum = m.count(RENLI);
    int yNum = m.count(YANFA);

    cout << "������Ա�����£�" << endl;
    for (int num = 0; cPos != m.end(), num < cNum; cPos++, num++)
    {
        cout << "������ " << cPos->second.mName << " ���ʣ� " << cPos->second.mMoney << endl;
    }
    cout << "-----------------------" << endl;

    cout << "��������Ա�����£�" << endl;
    for (int num = 0; rPos != m.end(), num < rNum; rPos++, num++)
    {
        cout << "������ " << rPos->second.mName << " ���ʣ� " << rPos->second.mMoney << endl;
    }
    cout << "-----------------------" << endl;

    cout << "�з�����Ա�����£�" << endl;
    for (int num = 0; yPos != m.end(), num < yNum; yPos++, num++)
    {
        cout << "������ " << yPos->second.mName << " ���ʣ� " << yPos->second.mMoney << endl;
    }
    cout << "-----------------------" << endl;
}
void showGroup2(multimap<int, Worker>&m)
{
    multimap<int, Worker>::iterator cPos = m.find(CAIWU);
    multimap<int, Worker>::iterator rPos = m.find(RENLI);
    multimap<int, Worker>::iterator yPos = m.find(YANFA);
    int cNum = m.count(CAIWU);
    int rNum = m.count(RENLI);
    int yNum = m.count(YANFA);

    cout << "������Ա�����£�" << endl;
    while (cPos != m.end() && cNum)
    {
        cout << "������ " << cPos->second.mName << " ���ʣ� " << cPos->second.mMoney << endl;
        cPos++;
        cNum--;
    }
    cout << "-----------------------" << endl;

    cout << "��������Ա�����£�" << endl;
    while (rPos != m.end() && rNum)
    {
        cout << "������ " << rPos->second.mName << " ���ʣ� " << rPos->second.mMoney << endl;
        rPos++;
        rNum--;
    }
    cout << "-----------------------" << endl;

    cout << "�з�����Ա�����£�" << endl;
    while (yPos != m.end() && yNum)
    {
        cout << "������ " << yPos->second.mName << " ���ʣ� " << yPos->second.mMoney << endl;
        yPos++;
        yNum--;
    }
    cout << "-----------------------" << endl;
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
    showGroup1(m);
    showGroup2(m);

    //��������
    /*for (vector<Worker>::iterator it = v.begin(); it != v.end();it++)
    {
    cout << "������ " << it->mName << " ���ʣ� " << it->mMoney << endl;
    }*/

    system("pause");
    return EXIT_SUCCESS;
}