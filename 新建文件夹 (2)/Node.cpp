#include "Node.h"


 list<Node *> Node::children;
  list<Node *> Node::nodes;
Node::Node() {
	parent = NULL;
	nodes.push_back(this);
}
Node::~Node() {
	nodes.remove(this);
}

void Node::addChild(Node * node) {
	this->children.push_back(node);
}
void Node::setParent(Node * p) {
	if (p != NULL &&parent != NULL) {
		removeselfFromParent();
		parent = p;
	}
	else if (p->getParent() != this) {
		parent = p;
		parent->addChild(this);
	}

}
 list<Node *> Node::getAllChildren() {

	 return children;
}
void Node::removeselfFromParent() {
	if (parent != NULL) {
		parent = NULL;
		parent->children.remove(this);
	}
}
Node * Node::getParent() {
	return parent;
}

list<Node *> Node::getNodes() {
	return nodes;
}