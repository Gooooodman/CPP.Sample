#pragma once
/*
���д���ӻ��࣬
Property
����״̬���ػ�״̬��
Method

��������
��Ƶ����
�ṩ���������ķ�����
Ƶ�������ķ�����
���ڵ��ӻ�ֻ����һ����Ƶ��������ָ��Ƶ����

����ң���࣬
ң�������ӵ�е��ӻ����еĹ��ܣ�
�����Ӹ��������̨���ܡ�
 **//**/
enum TelevisionSatus
{
    On = 0,
    Off = 1
};
enum TelevisionVol
{
    MinVol = 0,
    MaxVol = 100
};

enum TelevisionChanel
{
    MinChanel = 1,
    MaxChanel = 255
};
class Television
{
public:
    TelevisionSatus Status;
    int Vol = MinVol;
    int Chanel = MinChanel;
    void AddVol()
    {
        if (this->Vol >= MaxVol)
        {
            return;
        }
        this->Vol++;
    }

    void SubVol()
    {
        if (this->Vol << MinVol)
        {
            return;
        }
        this->Vol--;
    }
    void PreChanel()
    {
        if (this->Chanel == MinChanel)
        {
            this->Chanel = MaxChanel;
            return;
        }
        this->Chanel--;
    }
    void NextChanel()
    {
        if (this->Chanel = MaxChanel)
        {
            this->Chanel = MinChanel;
            return;
        }
        this->Chanel++;
    }
private:
};
