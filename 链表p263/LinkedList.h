#pragma once
#include "Node.h"
class LinkedList
{
public:
	LinkedList();
	bool empty()const;//�п�
	void insert(const int &value,const unsigned int &pos);//����value����pos֮���λ��
	void erase(const unsigned int &pos);//ɾ����pos��λ�õĽڵ�,��������Ԫ�أ���λ�÷ֱ�Ϊ0��1��2
	void push_back(const int &value);//��������һ���ڵ�
	void pop_back();//ɾ�����һ���ڵ�
	bool isAscOder()const;//�ж��������Ƿ�������
	void reserve();//��ת��������
	void dispaly()const;//�������Ԫ��
	~LinkedList();
private:
	Node * front;//ͷָ��
	Node * back;//βָ��
	/*
	���ڲ��ֺ���Ϊֻ��(���const��&����),
	����ʱ�޷���Current�������в���
	ֻ���ں����ڲ�����Currentָ��ʹ��.
	*/
	//Node * current;//��ǵ�ǰλ��ָ��
	unsigned int size;//����ڵ���
};

