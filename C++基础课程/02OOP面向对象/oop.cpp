#include <iostream>
#include <string>
#include "Person.h"
#include"Circle.h"
#include"Point.h"
#include "Student.h"
using namespace std;

namespace ��̬��Ա
{
    class Person
    {
    public:
        const static string Country;//�������޸�
        string Name;
        Person()
        {
            this->pTotal++;
        }

        Person(string name)
        {
            this->pTotal++;
            this->Name = name;
            cout << "------------------���죨" << this->Name << "---" << this << "��------------------" << endl;
        }

        int  GetTotal()
        {
            return this->pTotal;
        }

        void ShowTotal()
        {
            cout << "��������" << this->pTotal << endl;
        }
        static void Show()
        {
            //this->Country;
        }

        ~Person()
        {
            this->pTotal--;
            cout << "------------------������" << this->Name << "---" << this << "��------------------" << endl << endl;
        }
    private:
        static int pTotal;
    };
    const string Person::Country = "�й�";
    int   Person::pTotal = 0;

    void test()
    {
        Person p("A");
        cout << p.GetTotal() << endl;
        p.ShowTotal();

        p = Person("B");
        cout << p.GetTotal() << endl;
        p.ShowTotal();

        p = Person("C");
        cout << p.GetTotal() << endl;
        p.ShowTotal();

        p = Person("D");
        cout << p.GetTotal() << endl;
        p.ShowTotal();
    }
}

namespace ����ģ��
{
    class Person
    {
    public:
        //�Ǿ�̬��Ա������thisָ�룬��̬��Աû��
        void showPerson()
        {
            cout << this->mAge << endl;
        }

        //static  void showPerson()
        //{
        //    cout << this->mAge << endl;
        //}
    public:
        int mAge;
    };
    void test()
    {
        Person p1, p2;
        p1.showPerson();
        p2.showPerson();
        cout << sizeof Person << endl;
    }
}

namespace thisָ���ǿ
{
    class Person
    {
    public:
        Person()
        {
            cout << "Init" << endl;
        }
        ~Person()
        {
            cout << "Over" << endl;
        }
        void printPerson1()
        {
        }
        void printPerson2() const
        {
        }
        void showPerson() const
        {
            //this->mA = 123;   const ���εĺ����������ڱ��������޸ĳ�Ա������ֵ������mutable���εĳ�Ա������
            //const Person * const this �൱��this
            if (this)
            {
                this->mB = 123;
                cout << "Hello World" << endl;
            }
            else
            {
                cout << "Hello World NULL" << endl;
                return;
            }
        }
    public:
        int mA;
        mutable int mB;
        static int mC;
    };

    void test()
    {
        Person *person = NULL;
        person->showPerson(); //����
                              //person->mA = 123;      //�쳣

        const Person *person1 = new Person;
        //person1->printperson1();//������ֻ�ܵ��ø�������
        person1->printPerson2();
        //55 person1->mA = 123; //���������޸������ͨ��Ա����������mutabel���ε�
        person1->mB = 123; //������ֻ�ܷ���mutable���εĳ�Ա����
        //person1->mC = 456;
        delete person1;
    }
}

namespace friend��Ԫȫ�ֺ���
{
    class Building
    {
        //��Ԫֻ��������������ĳ�Ա
        friend class GoodFriend;
        friend void GoodGay(Building &building);
    public:
        Building()
        {
            mSittingRoom = "����";
            mBedRoom = "����";
        }
    public:
        string mSittingRoom;
    private:
        string mBedRoom;
    };
    class GoodFriend
    {
    public:
        void Visit(Building &xbuilding)
        {
            xbuilding.mBedRoom;
            xbuilding.mSittingRoom;
        }

        void Vist()
        {
            building.mSittingRoom = "";
            pBuilding->mSittingRoom = "";
        }
        void Clean()
        {
            building.mBedRoom = "";
            pBuilding->mBedRoom = "";
        }
    private:
        Building building;
        Building *pBuilding;
    };
    void GoodGay(Building &building)
    {
        building.mBedRoom = "";
        building.mSittingRoom = "";
    }
    void test()
    {
        Building building;
        GoodGay(building);
        //building.mBedRoom = "";//�˴���������
        building.mSittingRoom = "����";
    };
}

namespace ��Ԫ��Ա����
{
    class Person;
    class GirlFriend
    {
    public:
        void Talk(Person &person);
        void Beat(Person &person);
    };

    class Person
    {
        friend void GirlFriend::Beat(Person &person);

    private:
        string mName;
    };

    void GirlFriend::Talk(Person &person)
    {
    }
    void GirlFriend::Beat(Person &person)
    {
        person.mName;
    }
}

void Demo0()
{
    Person p;
    p.SetName("����");
    p.SetAge(20);

    cout << p.GetName() << "  " << p.GetAge() << endl;
    p.ShowPersonInfo();

    Person *per = new Person();
    per->SetName("����");
    delete per;
}
void Demo1()
{
    Circle circle;
    circle.setHeart(10, 10);
    circle.setR(20);

    Point point;
    point.setX(10);
    point.setY(30);

    circle.judgeCirleAndPointRelation(point);

    Circle *c = new Circle();
    delete c;
}
void Demo2()
{
    Student stu("��������", 3);
    stu.ShowInfo();
}
int main()
{
    int *p1 = new int;
    delete p1;
    int *p2 = new int;

    Demo2();
    system("pause");

    //int *pi = new int(5);
    //double *pd = new double();
    //char *pc = new char[10];
    //string *ps = new string(10);  //error
    return 0;
}