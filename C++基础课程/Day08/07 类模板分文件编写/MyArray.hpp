#pragma once
#include<iostream>

//template<class T> class MyArray;

//template<class T> void showArray(MyArray<T> &arr);
//template<class T> std::ostream& operator<<(std::ostream& out, MyArray<T> &arr);

template<class T>
class MyArray
{
    //��ͨ�������� ���� ����ģ��������
    //����һ����ͨ��������
    //friend std::ostream& operator<<<>(std::ostream& out, MyArray<T> &arr);

    //��Ԫ����ģ��
    //template<class TT> friend void showArray(MyArray<TT> &arr);

    //friend void showArray<>(MyArray<T> &arr);

public:
    T *pAddress;
    int mSize;
    int mCapcity;

public:
    MyArray(int size);
    ~MyArray();
    void Push(const T &pAddress)
    {
        if (this->mSize >= mCapcity)
        {
            return;
        }
        else
        {
            this->pAddress[mSize] = pAddress;
            mSize++;
        }
    }

    T operator[] (int index)
    {
        if (this->mCapcity <= index)
        {
            throw string("����Խ��");
        }
        return   this->pAddress[index];
    }
};

template<class T> MyArray<T>::MyArray(int size)
{
    this->pAddress = new T[size];
    this->mCapcity = size;
}

template<class T> MyArray<T>::~MyArray()
{
    //����Խ�磬������ٿռ䣬�����ͷŶ����ڴ�
    delete this->pAddress;
}

template<class T> std::ostream& operator<<(std::ostream& out, MyArray<T> &arr)
{
    showArray(arr);
    return out;
}

template<class T> void showArray(MyArray<T> &arr)
{
    for (int i = 0; i < arr.mSize; i++)
    {
        cout << arr.pAddress[i] << "  ";
    }
    cout << endl;
}