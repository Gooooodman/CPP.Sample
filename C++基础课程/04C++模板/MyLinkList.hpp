#include <iostream>

//���ļ���д����
/************************************************************************/
/* 1:��ģ������
 * 2����ģ�涨��
 * 3����ģ�溯�������Ķ��壨����ָ�����ͣ�
/************************************************************************/

 

template<class T>
class LinkNode
{
public:
    T *pData;
    LinkNode  *pNext;

public:
    LinkNode(T *data);
};

template<class T>
LinkNode<T>::LinkNode(T *data)
{
    this->pData = new T(sizeof(T));
    this->pData = data;
}

 

template<class T>
class LinkList
{
public:
    LinkList();

    void Push(T t);

public:
    LinkNode<T>   pHeader;
    LinkNode<T>   pFooted;
    int mSize;
};

template<class T>
LinkList<T>::LinkList()
{
    cout << "  " << endl;
}

template<class T>
void LinkList<T>::Push(T t)
{
    cout << "" << endl;
}