#pragma once
#include <vector>
#include <list>
#include <gl\glut.h>
using std::vector;
using std::list;
class Node
{
public:
	Node();
	virtual ~Node();

	void addChild(Node * node);
	void setParent(Node * parent);
	Node * getParent();
	void removeselfFromParent();
	list<Node *> getAllChildren();
	static list<Node *> getNodes();
protected:
	

private :
	static list<Node *> children;
		Node * parent;
	static list<Node *> nodes;
	
};

