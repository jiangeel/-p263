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
		cout << "错误：待位置超过链表长度" << endl;
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
		current = current->next;  //current移到待添加的前一个节点
	}
	Node *newNode = new Node(value, current->next);
	current->next = newNode;

}

void LinkedList::erase(const unsigned int & pos)
{
	if (pos>=size)
	{
		cout << "错误：待位置超过链表长度" << endl;
		return;
	}
	if (pos+1==size)
	{
		pop_back();
	}
	Node *current = front;
	for (unsigned int i=1;i<pos;i++)
	{
		current = current->next;  //current移到待删除的前一个节点
	}
	Node *p = current->next;//保存待删除的节点准备删除
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
		cout << "错误：链表为空无法删除" << endl;
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
	bool flag = 1;//假设为升序
	Node *current = front;
	if (size != 0 && size != 1)//如果长度是0或1的话，直接返回true
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
