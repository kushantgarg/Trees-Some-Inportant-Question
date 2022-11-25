#include<iostream>
#include<stack>
#include<stdlib.h>
using namespace std;
class node{
	public:
		int data;
		node *left;
		node *right;
};


node * createnode(int data)
{
	node *n=new node();
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;

}
void inorder(node *root)
{
	node *ptr=root;
   stack<node*>s;
   s.push(NULL);
   while(ptr!=NULL||!s.empty())
   {
   	while(ptr!=NULL)
   	{
   		s.push(ptr);
   		ptr=ptr->left;
	   }
	 
	   ptr=s.top();//poping the values
	 
	   s.pop();
	   
	   cout<<ptr->data<<" ";
	   ptr=ptr->right;
   }
		
}
int main()
{
	node *p;
	p=createnode(1);
	node*p1=createnode(2);
node*p2=createnode(3);
node*p3=createnode(4);
node*p4=createnode(5);
//linking of nodes as descendents of parent nodes
p->left=p1;
p->right=p2;
p1->left=p3;
p1->right=p4;
inorder(p);
}
