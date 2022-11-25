#include<iostream>
#include<stdlib.h>
using namespace std;
class node{
	public:
		int data;
		node *left;
		node *right;
};
node * create_node(int data)//function for creating a node
{
    node *n;
    n=new node();
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
 int main()
 {
 	node*p;
 	p=create_node(2);//creating root node;
 	node *p1;
	 node *p2;
 	p1=create_node(3);
 	p2=create_node(4);
 	//linking p1 and p2 with the root node
 	p->left=p1;
 	p->right=p2;
 }

