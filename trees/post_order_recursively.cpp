#include<iostream>
#include<stdlib.h>
using namespace std;
class node{
	public:
		int data;
		node *left;
		node *right;
};

node * create_node(int data)
{
	node *n=new node();
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}
 void postorder(node *root)
 {
 	if(root!=NULL)
 	{
 		
 		postorder(root->left);
 		postorder(root->right);
 		cout<<root->data<<" ";
	 }
 	return;
 }

int main()
{
	node *p=create_node(4);
	node *p1=create_node(1);
	node *p2=create_node(6);
	node *p3=create_node(5);
	node *p4=create_node(2);
	p->left=p1;
	p->right=p2;
	p1->left=p3;
	p1->right=p4;
	postorder(p);
	return 0;
}
