#pragma once
#include "Node.h"
class LinkedList
{
public:
	LinkedList();
	bool empty()const;//判空
	void insert(const int &value,const unsigned int &pos);//插入value到第pos之后的位置
	void erase(const unsigned int &pos);//删除第pos个位置的节点,若有三个元素，则位置分别为0，1，2
	void push_back(const int &value);//在最后加入一个节点
	void pop_back();//删除最后一个节点
	bool isAscOder()const;//判断链表内是否是升序
	void reserve();//反转整个链表
	void dispaly()const;//输出所有元素
	~LinkedList();
private:
	Node * front;//头指针
	Node * back;//尾指针
	/*
	由于部分函数为只读(添加const和&引用),
	遍历时无法对Current变量进行操作
	只能在函数内部申请Current指针使用.
	*/
	//Node * current;//标记当前位置指针
	unsigned int size;//链表节点数
};

