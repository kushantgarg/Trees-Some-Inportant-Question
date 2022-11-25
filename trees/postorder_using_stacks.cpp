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
  while(ptr!=NULL || !s.empty())
  {
  	while(ptr!=NULL)
  	{
  		s.push(ptr);
  		if(ptr->right!=NULL)
  		{
  		   s.push((ptr->right));
		  }
		  ptr=ptr->left;
  		
	  }
		  }		
		  //after completion of loop means no left child left
		  //pop the value
		  ptr=s.top();
		  while(ptr>0)
		  {
		  	cout<<ptr->data;
		  	ptr=s.top();
		  }
		  //when ptr<0 means right child comes
		  ptr=(ptr);
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
