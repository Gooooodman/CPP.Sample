#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
    virtual void Speak() = 0;
    virtual ~Animal() {}
};

class Chicken : public Animal
{
public:
    virtual void Speak()
    {
        cout << "С��������..." << endl;
    }
};

class Tiger : public Animal
{
public:
    virtual void Speak()
    {
        cout << "�ϻ����..." << endl;
    }
};

class Dog : public Animal
{
public:
    virtual void Speak()
    {
        cout << "С��������..." << endl;
    }
};

class Cat : public Animal
{
public:
    virtual void Speak()
    {
        cout << "Сè������..." << endl;
    }
};

class Duck : public Animal
{
public:
    virtual void Speak()
    {
        cout << "Ѽ�Ӹ¸¸�..." << endl;
    }
};

class Snake : public Animal
{
public:
    Snake()
    {
        mSpeed = 100;
    }
    virtual void Speak()
    {
        dance();
        cout << "������" << mSpeed << "ʱ����ǰ��!" << endl;
    }
    void dance()
    {
        cout << "С��Ť��ƨ����ǰ��..." << endl;
    }
public:
    int mSpeed;
};

class Zoo
{
public:
    Zoo()
    {
        pAnimals = new Animal*[20];
        mSize = 0;
    }

    //����԰������µĶ���
    void addNewAnimal(Animal *animal)
    {
        if (mSize == 20)
        {
            return;
        }
        this->pAnimals[mSize++] = animal;
    }

    //������ݣ���ʼ��
    void startKTV()
    {
        for (int i = 0; i < mSize; ++i)
        {
            this->pAnimals[i]->Speak();
        }
    }

    //��������
    ~Zoo()
    {
        for (int i = 0; i < mSize; ++i)
        {
            if (this->pAnimals[i] != NULL)
            {
                delete this->pAnimals[i];
                this->pAnimals[i] = NULL;
            }
        }

        //������԰
        delete[] this->pAnimals;
        this->pAnimals = NULL;
        mSize = 0;
    }
public:
    Animal **pAnimals;
    int mSize;
};

void test()
{
    //��������԰
    Zoo zoo;
    zoo.addNewAnimal(new Tiger);
    zoo.addNewAnimal(new Duck);
    zoo.addNewAnimal(new Dog);
    zoo.addNewAnimal(new Cat);
    zoo.addNewAnimal(new Chicken);
    zoo.addNewAnimal(new Duck);
    zoo.addNewAnimal(new Snake);

    zoo.startKTV();

#if 0
    Animal *animal = NULL;
    animal = new Duck;
    animal->Speak();
    delete animal;

    animal = new Tiger;
    animal->Speak();
    delete animal;
#endif
}

int main() {
    test();

    system("pause");
    return EXIT_SUCCESS;
}