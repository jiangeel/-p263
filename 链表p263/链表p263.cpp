// ����p263.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
#include "LinkedList.h"
using namespace std;
int main()
{
	cout << "������Ҫ��������" << endl;
	//�½�һ��������
	LinkedList list;
	//����push_back
	for (int i=0;i<1000;i++)
	{
		list.push_back(i);
	}
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
	return 0;
}

