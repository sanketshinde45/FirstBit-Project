#include"Node.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Node::Node(Player &d)
{
	data = d;
	next = NULL;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Node::setData(Player &d)
{
	this->data=d;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
void Node::setNext(Node* nxt)
{
	this->next=nxt;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
Player Node::getData()
{
	return data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
Node* Node::getNext()
{
	return next;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
