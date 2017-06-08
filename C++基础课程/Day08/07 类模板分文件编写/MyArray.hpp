#pragma once
#include<iostream>

template<class T> class MyArray;

//template<class T> void showArray(MyArray<T> &arr);
template<class T> std::ostream& operator<<(std::ostream& out, MyArray<T> &arr);

template<class T>
class MyArray
{
    //��ͨ�������� ���� ����ģ��������
    //����һ����ͨ��������
    friend std::ostream& operator<<<>(std::ostream& out, MyArray<T> &arr);
    //friend void showArray<>(MyArray<T> &arr);

    //��Ԫ����ģ��
    template<class TT> friend void showArray(MyArray<TT> &arr);
public:
    MyArray();
    ~MyArray();
    void Push(const T &pAddress)
    {
        if (this->mSize >= 10)
        {
            return;
        }
        else
        {
            this->pAddress[mSize] = pAddress;
            mSize++;
        }
    }
public:
    T *pAddress;
    int mSize;
};

template<class T> MyArray<T>::MyArray()
{
    this->pAddress = new T[10];
}

template<class T> MyArray<T>::~MyArray()
{
    //for (int i = 0; i < this->mSize; i++)
    //{
    //    delete this->pAddress[i];
    //    this->pAddress[i] = NULL;
    //}
    //����Խ�磬������ٿռ䣬�����ͷŶ����ڴ�
    delete this->pAddress;
}

template<class T> std::ostream& operator<<(std::ostream& out, MyArray<T> &arr)
{
    return out;
}

template<class T> void showArray(MyArray<T> &arr)
{
    for (int i = 0; i < arr.mSize; i++)
    {
        cout << arr.pAddress[i] << "  ";
    }
    cout << "��ͨ��Ԫ������" << endl;
}