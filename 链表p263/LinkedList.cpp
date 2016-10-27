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
	if (pos+1==size)
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
	if (pos+1==size)
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
	delete p;
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
		delete current;
	}
	while (current->next!=back)
	{
		current = current->next;
	}
	delete back;
	back = current;

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

}

void LinkedList::dispaly() const
{
	Node *current = front;
	while (current!=NULL)
	{
		cout << current->value << ' ';
		current = current->next;
	}
	cout << endl;
}


LinkedList::~LinkedList()
{
}
