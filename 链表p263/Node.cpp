#include "stdafx.h"
#include "Node.h"


Node::Node()
{
	value = 0;
	next = NULL;
}

Node::Node(int v, Node * n)
{
	value = v;
	next = n;
}


Node::~Node()
{
}
