// ����p263.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
#include "LinkedList.h"
using namespace std;
int main()
{
	cout << "������Ҫ��������" << endl << endl;
	//�½�һ��������
	LinkedList list;
	//��ʼ������Գ���
	const int N = 20;
	//����push_back
	for (int i=0;i<N;i++)
	{
		list.push_back(i);
	}
	cout << "��ʼ��һ������" << endl;
	list.dispaly();

	//����pop_back
	cout << "ɾ�����һ��Ԫ��" << endl;
	list.pop_back();
	list.dispaly();

	//����isAscOder
	cout <<"������������?  "<<boolalpha<< list.isAscOder() << endl;
	//����insert
	cout <<endl<< "�ڵ�5��Ԫ��֮�����ֵ100" << endl;
	list.insert(100, 5);
	list.dispaly();
	cout << "������������?  " << boolalpha << list.isAscOder() << endl;

	//����erase
	cout << endl << "ɾȥ��7��Ԫ��" << endl;
	list.erase(7);
	list.dispaly();

	//����reserve
	cout << endl << "��ת����" << endl;
	list.reserve();
	list.dispaly();

	cout << endl;

	//�����������������
	int arrA[8] = { 88,2,4,6,3,5,23,65 };
	int arrB[9] = { 34,1,23,87,23,12,43,74,34 };

	//������arrA��arrB���뵽�����У������Դ�ӡ����Ԫ��
	cout << "�ڶ������:" << endl;
	cout << "������arrA��arrB���뵽�����У������Դ�ӡ����Ԫ��:" << endl;
	LinkedList ListA1 = LinkedList(arrA, 8);
	cout << "ListA1:  "; ListA1.dispaly();
	LinkedList ListB1 = LinkedList(arrB, 9);
	cout << "ListB1:  "; ListB1.dispaly();
	////������ListA1��ListB1���������γ�A2��B2������ӡ
	cout << endl << "����������:" << endl;
	LinkedList ListA2 = ListA1.sortByAsc();
	cout << "ListA1:  "; ListA2.dispaly();
	cout << "����Ϊ����:" << boolalpha << ListA2.isAscOder() << endl;//�鿴������
	LinkedList ListB2 = ListB1.sortByAsc();
	ListB2.sortByAsc();
	cout << "ListB2:  "; ListB2.dispaly();
	cout << "����Ϊ����:" << ListB2.isAscOder() << endl;//�鿴������
												   //�ϲ�����A2��B2���γ�listC����������Ϊ���򣬲���ӡ
	cout << endl << "�ϲ��������:" << endl;
	LinkedList ListC = ListA2.merge(ListB2);
	ListC.dispaly();
	return 0;
}

