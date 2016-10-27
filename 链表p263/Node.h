#pragma once
class Node
{
public:
	Node();
	Node(int value,Node *next );
	~Node();

	int value;
	Node *next;
};

