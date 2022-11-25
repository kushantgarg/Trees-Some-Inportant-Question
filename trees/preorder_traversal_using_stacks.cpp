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
void preorder(node *root)
{
	//cout<<root->data;
	node *ptr;
	ptr=root;
	//cout<<ptr->data;
	stack<node*>s;
	//node *ptr=root;
	//cout<<ptr->data;
	s.push(NULL);
	while(ptr!=NULL||!s.empty())
	{
	 
	     
		//processing each node and checking its left and right child
		while(ptr!=NULL)
		{
			
			cout<<ptr->data<<" ";
			if(ptr->right!=NULL)
		{
		       s.push(ptr->right);
		       
		}
		
			ptr=ptr->left;
			

	}
	
        //when no left child left we pop out and assing it to ptr
        // take out a right child from stack
        if (!s.empty()) {
          ptr=s.top();
          s.pop();
            
            
        }
        
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
preorder(p);
}
