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
	if (pos+1==size)//插入在最后则调用push_back()
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
	if (pos+1==size)//删除的是最后一个则调用pop_back()
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
		cout << "错误：链表为空无法删除" << endl;
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
	Node *current1 = front;
	//对链表长度为空,1,2分别单独操作
	if (empty())
	{
		cout << "错误:链表为空,无法反转" << endl;
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

	//链表长度大于2时的常规操作
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
	//复杂度n^2
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


//拷贝构造函数实现深拷贝
LinkedList::LinkedList(const LinkedList& L)
{
	Node *current = L.front;
	size = 0;
	front = NULL;
	back = NULL;
	while (current != NULL)//遍历整个链表，分别复制每个节点
	{
		this->push_back(current->value);
		current = current->next;
	}
}

//用一个静态数组初始化链表的构造函数
LinkedList::LinkedList(int a[], const unsigned int &len)
{
	front = NULL;
	back = NULL;
	size = 0;
	for (unsigned int i = 0; i < len; i++)
	{
		this->push_back(a[i]);//将数组所有元素依次插入至链表末尾
	}
}

//将链表升序排列
LinkedList LinkedList::sortByAsc() const
{
	if (size == 0 || size == 1)//长度为0或1的话无需排序
	{
		return *this;
	}
	LinkedList L2 = *this;//为了不破坏原数组,先复制一份

						  //在尾部和首部分别添加一个空白节点
	Node *b = new Node(10086, NULL);
	Node *p = new Node(10010, L2.front);
	L2.front = p;
	L2.back->next = b;
	L2.back = b;
	//遍历链表,寻找最小的节点,并将其移到尾空白节点之后
	while (L2.front->next != b)
	{
		p = L2.front->next;

		Node *current = p;
		Node *previous = L2.front;
		Node *min = p;
		Node *minPre = L2.front;
		//寻找值最小的节点,并记录为min
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
		//将min节点移动到尾部空白节点之后
		minPre->next = min->next;
		L2.back->next = min;
		L2.back = min;

	}
	//循环结束后链表为两个空白节点+已排序完成的链表
	//删除首空白节点
	delete L2.front;
	//头指针指向第一个有意义节点
	L2.front = b->next;
	//尾指针指向最后一个有意义节点
	L2.back->next = NULL;
	//删除尾空白节点
	delete b;


	return L2;
}

//将链表L融合进原链表,合并后仍为升序
LinkedList LinkedList::merge(const LinkedList & L)
{
	//为不破坏数组,先复制一份原来链表
	LinkedList L2 = L;
	LinkedList L3 = *this;

	Node *current2 = L2.front;
	Node *previous2 = L2.front;
	Node *current3 = L3.front;
	Node *previous3 = L3.front;

	//L2或L3任一链表遍历完即停止循环,并将剩余的节点连到最后
	while (current3 != NULL&&current2 != NULL)
	{

		if (current2->value >= current3->value)//找到L2首节点的插入位置
		{
			previous3 = current3;
			current3 = current3->next;
			continue;
		}
		previous2 = current2;
		//指向下一个待插入的节点
		current2 = current2->next;
		//L2的首节点插入到L3中
		previous2->next = current3;
		//如果带插入节点比L3的首节点还小的话,要修改L3的头指针
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
	if (current2 != NULL)//最后如果L2有剩余
	{
		previous3->next = current2;//把L2剩余的加上
		L3.back = L2.back;
	}
	L2.front = NULL;//L2已经并入L3，因此L2已经为空.(不加的话L2析构时会出问题)
	return L3;
}


//重载赋值符号
LinkedList & LinkedList::operator=(const LinkedList & L1)
{
	front = NULL;
	back = NULL;
	size = 0;
	Node *current = L1.front;
	while (current != NULL)//将L1的每一个节点赋值一遍
	{
		this->push_back(current->value);
		current = current->next;
	}
	return *this;
}

//析构函数,从头依次删除每一个节点
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
