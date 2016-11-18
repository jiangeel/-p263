// 链表p263.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "LinkedList.h"
using namespace std;
int main()
{
	cout << "链表主要函数测试" << endl << endl;
	//新建一个空链表
	LinkedList list;
	//初始链表测试长度
	const int N = 20;
	//测试push_back
	for (int i=0;i<N;i++)
	{
		list.push_back(i);
	}
	cout << "初始化一个链表" << endl;
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

	//定义两个无序的数组
	int arrA[8] = { 88,2,4,6,3,5,23,65 };
	int arrB[9] = { 34,1,23,87,23,12,43,74,34 };

	//将数组arrA、arrB导入到链表中，并各自打印链表元素
	cout << "第二组测试:" << endl;
	cout << "将数组arrA、arrB导入到链表中，并各自打印链表元素:" << endl;
	LinkedList ListA1 = LinkedList(arrA, 8);
	cout << "ListA1:  "; ListA1.dispaly();
	LinkedList ListB1 = LinkedList(arrB, 9);
	cout << "ListB1:  "; ListB1.dispaly();
	////将链表ListA1、ListB1各自排序，形成A2和B2，并打印
	cout << endl << "排序后的数组:" << endl;
	LinkedList ListA2 = ListA1.sortByAsc();
	cout << "ListA1:  "; ListA2.dispaly();
	cout << "链表为升序:" << boolalpha << ListA2.isAscOder() << endl;//查看排序结果
	LinkedList ListB2 = ListB1.sortByAsc();
	ListB2.sortByAsc();
	cout << "ListB2:  "; ListB2.dispaly();
	cout << "链表为升序:" << ListB2.isAscOder() << endl;//查看排序结果
												   //合并链表A2和B2，形成listC，并仍排列为升序，并打印
	cout << endl << "合并后的数组:" << endl;
	LinkedList ListC = ListA2.merge(ListB2);
	ListC.dispaly();
	return 0;
}

