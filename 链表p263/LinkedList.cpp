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


//�������캯��ʵ�����
LinkedList::LinkedList(const LinkedList& L)
{
	Node *current = L.front;
	size = 0;
	front = NULL;
	back = NULL;
	while (current != NULL)//�������������ֱ���ÿ���ڵ�
	{
		this->push_back(current->value);
		current = current->next;
	}
}

//��һ����̬�����ʼ������Ĺ��캯��
LinkedList::LinkedList(int a[], const unsigned int &len)
{
	front = NULL;
	back = NULL;
	size = 0;
	for (unsigned int i = 0; i < len; i++)
	{
		this->push_back(a[i]);//����������Ԫ�����β���������ĩβ
	}
}

//��������������
LinkedList LinkedList::sortByAsc() const
{
	if (size == 0 || size == 1)//����Ϊ0��1�Ļ���������
	{
		return *this;
	}
	LinkedList L2 = *this;//Ϊ�˲��ƻ�ԭ����,�ȸ���һ��

						  //��β�����ײ��ֱ����һ���հ׽ڵ�
	Node *b = new Node(10086, NULL);
	Node *p = new Node(10010, L2.front);
	L2.front = p;
	L2.back->next = b;
	L2.back = b;
	//��������,Ѱ����С�Ľڵ�,�������Ƶ�β�հ׽ڵ�֮��
	while (L2.front->next != b)
	{
		p = L2.front->next;

		Node *current = p;
		Node *previous = L2.front;
		Node *min = p;
		Node *minPre = L2.front;
		//Ѱ��ֵ��С�Ľڵ�,����¼Ϊmin
		while (current != b)
		{
			if (current->value <= min->value)
			{
				min = current;
				minPre = previous;
			}
			previous = current;
			current = current->next;
		}
		//��min�ڵ��ƶ���β���հ׽ڵ�֮��
		minPre->next = min->next;
		L2.back->next = min;
		L2.back = min;

	}
	//ѭ������������Ϊ�����հ׽ڵ�+��������ɵ�����
	//ɾ���׿հ׽ڵ�
	delete L2.front;
	//ͷָ��ָ���һ��������ڵ�
	L2.front = b->next;
	//βָ��ָ�����һ��������ڵ�
	L2.back->next = NULL;
	//ɾ��β�հ׽ڵ�
	delete b;


	return L2;
}

//������L�ںϽ�ԭ����,�ϲ�����Ϊ����
LinkedList LinkedList::merge(const LinkedList & L)
{
	//Ϊ���ƻ�����,�ȸ���һ��ԭ������
	LinkedList L2 = L;
	LinkedList L3 = *this;

	Node *current2 = L2.front;
	Node *previous2 = L2.front;
	Node *current3 = L3.front;
	Node *previous3 = L3.front;

	//L2��L3��һ��������꼴ֹͣѭ��,����ʣ��Ľڵ��������
	while (current3 != NULL&&current2 != NULL)
	{

		if (current2->value >= current3->value)//�ҵ�L2�׽ڵ�Ĳ���λ��
		{
			previous3 = current3;
			current3 = current3->next;
			continue;
		}
		previous2 = current2;
		//ָ����һ��������Ľڵ�
		current2 = current2->next;
		//L2���׽ڵ���뵽L3��
		previous2->next = current3;
		//���������ڵ��L3���׽ڵ㻹С�Ļ�,Ҫ�޸�L3��ͷָ��
		if (previous3 == L3.front)
		{
			L3.front = previous2;
			previous3 = previous2;
		}
		else
		{
			previous3->next = previous2;
			previous3 = previous2;
		}

	}
	if (current2 != NULL)//������L2��ʣ��
	{
		previous3->next = current2;//��L2ʣ��ļ���
		L3.back = L2.back;
	}
	L2.front = NULL;//L2�Ѿ�����L3�����L2�Ѿ�Ϊ��.(���ӵĻ�L2����ʱ�������)
	return L3;
}


//���ظ�ֵ����
LinkedList & LinkedList::operator=(const LinkedList & L1)
{
	front = NULL;
	back = NULL;
	size = 0;
	Node *current = L1.front;
	while (current != NULL)//��L1��ÿһ���ڵ㸳ֵһ��
	{
		this->push_back(current->value);
		current = current->next;
	}
	return *this;
}

//��������,��ͷ����ɾ��ÿһ���ڵ�
LinkedList::~LinkedList()
{
	Node *current = front;
	while (front != NULL)
	{
		current = current->next;
		delete front;
		front = current;
	}
}
