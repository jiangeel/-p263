// 链表p263.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "LinkedList.h"
using namespace std;
int main()
{
	cout << "链表主要函数测试" << endl;
	//新建一个空链表
	LinkedList list;
	//测试push_back
	for (int i=0;i<1000;i++)
	{
		list.push_back(i);
	}
	list.dispaly();

	//测试pop_back
	cout << "删除最后一个元素" << endl;
	list.pop_back();
	list.dispaly();

	//测试isAscOder
	cout <<"数组是升序吗?  "<<boolalpha<< list.isAscOder() << endl;
	//测试insert
	cout <<endl<< "在第5个元素之后插入值100" << endl;
	list.insert(100, 5);
	list.dispaly();
	cout << "数组是升序吗?  " << boolalpha << list.isAscOder() << endl;

	//测试erase
	cout << endl << "删去低7个元素" << endl;
	list.erase(7);
	list.dispaly();

	//测试reserve
	cout << endl << "反转链表" << endl;
	list.reserve();
	list.dispaly();

	cout << endl;
	return 0;
}

