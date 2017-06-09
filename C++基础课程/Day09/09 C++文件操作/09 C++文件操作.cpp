#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;

//1. �ı���ʽ��д�ļ�
void test01()
{
	//1. �����ļ����������
	//ofstream ofs("./test.txt", ios::out );
	ofstream ofs;
	ofs.open("./test.txt", ios::out);

	//2. �ж��ļ��Ƿ��
	if (!ofs)
	{
		cout << "�ļ���ʧ��!" << endl;
	}

	//3. ���ļ���д������
	char *buf[] = {
		"aaaaaaaaaaaaa\n",
		"bbbbbbbbbbbbbbbbbbbbb\n",
		"cccccccccccccccccccccc\n",
		"ddddddddd\n"
	};
	int len = sizeof(buf) / sizeof(char *);

#if 0
	for (int i = 0; i < len; ++i)
	{
		int lineLen = strlen(buf[i]);
		for (int j = 0; j < lineLen; ++j)
		{
			ofs.put(buf[i][j]);
		}
	}
#endif

	for (int i = 0; i < len; ++i)
	{
		ofs << buf[i];
	}
	//�ر��ļ�
	ofs.close(); //ˢ�»������� �ر��ļ�

	/*************************/

	//���ļ�
	ifstream ifs("./test.txt",ios::in);
	if (!ifs)
	{
		cout << "�ļ���ʧ��!" << endl;
	}

	char buf2[1024] = { 0 };
	while (ifs >> buf2)
	{
		cout << buf2 << endl;
		memset(buf2, 0, 1024);
	}

	//�ر��ļ�
	ifs.close();
}

//2. �������ļ���д
class Person
{
public:
	Person(const char *name,int age)
	{
		//memset(mName, 0, 64);
		strcpy(mName, name);
		mAge = age;
	}
public:
	char mName[64];
	int mAge;
};
void test02()
{
	//��������
	Person persons[3]{Person("aaa", 10), Person("bbb", 20), Person("ccc", 30)};
	//������д���ļ�
	ofstream ofs("./persons.txt", ios::out | ios::binary);
	if (!ofs)
	{
		cout << "��ʧ��!" << endl;
	}
	//�������Զ����Ƶķ�ʽд���ļ�
	ofs.write((const char *)persons, sizeof(Person)* 3);
	//�ر��ļ�
	ofs.close();

	/*******************/
	ifstream ifs("./persons.txt", ios::in | ios::binary);
	if (!ifs)
	{
		cout << "��ʧ��!" << endl;
	}

	//�����ڴ�
	char *person = (char *)malloc(sizeof(Person)* 3);
	memset(person, 0, sizeof(Person)* 3);

	ifs.read(person, sizeof(Person) *3);

	Person *ps = (Person *)person;

	for (int i = 0; i < 3; ++i)
	{
		cout << "Name:" << ps[i].mName << " Age:" << ps[i].mAge << endl;
	}

	free(person);

	//�ر��ļ�
	ifs.close();

}

//�ļ���дע��
//eof
//fail
//bad �����޸�
//good
void  test03()
{

	//���ļ�
	ifstream ifs("./test.txt", ios::in);
#if 0
	ifs.fail();
	ifs.bad();
	ifs.eof();
	ifs.good();
#endif
	if (!ifs)
	{
		cout << "�ļ���ʧ��!" << endl;
	}

	char buf2[1024] = { 0 };
	while (ifs >> buf2)
	{
		cout << buf2 << endl;
		memset(buf2, 0, 1024);
	}


	cout << "--------------" << endl;
	cout << boolalpha << ifs.good();

	ifs.clear();
	//�ļ�ָ������Ϊ��ʼλ��
	ifs.seekg(0,ios::beg);

	while (ifs >> buf2)
	{
		cout << buf2 << endl;
		memset(buf2, 0, 1024);
	}

	//�ر��ļ�
	ifs.close();
}

void  test04()
{
	char buf[1] = { 0 };
	cin.getline(buf,1);

	cout << boolalpha << cin.fail() << endl;
	cout << boolalpha << cin.good() << endl;

	char b[1024] = { 0 };
	cin.get(b,1024);
	cout << b << endl;
}

int main(){

	//test01();
	//test02();
	//test03();
	test04();

	system("pause");
	return EXIT_SUCCESS;
}