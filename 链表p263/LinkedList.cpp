#include "stdafx.h"
#include "LinkedList.h"
#include "iostream"
using namespace std;

LinkedList::LinkedList()
{
	front = NULL;
	//current = NULL;
	back = NULL;
	size = 0;
}

bool LinkedList::empty() const
{
	return size==0;
}

void LinkedList::insert(const int & value, const unsigned int & pos)
{
	if (pos >= size)
	{
		cout << "���󣺴�λ�ó���������" << endl;
		return;
	}
	if (pos+1==size)//��������������push_back()
	{
		push_back(value);
		return;
	}
	Node *current = front;
	for (unsigned int i = 0; i < pos; i++)
	{
		current = current->next;  //current�Ƶ�����ӵ�ǰһ���ڵ�
	}
	Node *newNode = new Node(value, current->next);
	current->next = newNode;

}

void LinkedList::erase(const unsigned int & pos)
{
	if (pos>=size)
	{
		cout << "���󣺴�λ�ó���������" << endl;
		return;
	}
	if (pos+1==size)//ɾ���������һ�������pop_back()
	{
		pop_back();
	}
	Node *current = front;
	for (unsigned int i=1;i<pos;i++)
	{
		current = current->next;  //current�Ƶ���ɾ����ǰһ���ڵ�
	}
	Node *p = current->next;//�����ɾ���Ľڵ�׼��ɾ��
	current->next = current->next->next;
	if (p!=NULL)
	{
		delete p;
	}
}

void LinkedList::push_back(const int & value)
{
	Node *newNode = new Node(value, NULL);

	if (empty())
	{
		front = newNode;
		back = newNode;
	}
	else
	{
		back->next = newNode;
		back = newNode;
	}
	size++;
}

void LinkedList::pop_back()
{
	if (empty())
	{
		cout << "��������Ϊ���޷�ɾ��" << endl;
		return;
	}
	Node *current = front;
	if (size == 1)
	{
		front = NULL;
		back = NULL;
		if (current!=NULL)
		{
			delete current;
		}
		size--;
		return;
	}

	while (current->next!=back)
	{
		current = current->next;
	}
	if (back!=NULL)
	{
		delete back;
	}
	back = current;
	back->next = NULL;
	size--;

}

bool LinkedList::isAscOder() const
{
	bool flag = 1;//����Ϊ����
	Node *current = front;
	if (size != 0 && size != 1)//���������0��1�Ļ���ֱ�ӷ���true
	{
		while(current->next != NULL)
		{
			if (current->value > current->next->value)
			{
				flag = 0;
				break;
			}
			current = current->next;
		} 
	}
	return flag;
}

void LinkedList::reserve()
{
	Node *current1 = front;
	//��������Ϊ��,1,2�ֱ𵥶�����
	if (empty())
	{
		cout << "����:����Ϊ��,�޷���ת" << endl;
		return;
	}
	if (size==1)
	{	return;	}
	if (size==2)
	{
		back->next = front;
		front->next = NULL;
		front = back;
		back = current1;
		return;
	}

	//�����ȴ���2ʱ�ĳ������
	Node *current2 = front->next;
	Node *current3 = front->next;
	current1->next= NULL;
	for (unsigned int i=1;i<size;i++)
	{
		current3= current3->next;
		current2->next = current1;
		current1 = current2;
		current2 = current3;
	}
	back = front;
	front = current1;
	//���Ӷ�n^2
	/*for (int i = 0; i <size-1 ; i++)
	{
		Node *currentF = front;
		Node *currentB = back;
		for (int j=size-2;j>i;j--)
		{
			currentF = currentF->next;
		}
		for (int k=0;k<i;k++)
		{
			currentB = currentB->next;
		}
		currentB->next = currentF ;
	}
	front = back;
	back = current;
	back->next = NULL;*/
	return;
}

void LinkedList::dispaly() const
{
	Node *current = front;
	while (current!=NULL)
	{
		cout << current->value << ' ';
		current = current->next;
	}
	cout <<"  size: "<< size<<endl;
}


LinkedList::~LinkedList()
{
}
