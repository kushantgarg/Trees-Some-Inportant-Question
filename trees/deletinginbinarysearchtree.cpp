//boilerplate code

#include<iostream>
#include<stdlib.h>
using namespace std;
class node{
	public:
		int data;
		node *right;
		node *left;
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
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
void preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
		
	}
}
int isBST(node *root)
{
	static node *prev=NULL;
	if(root!=NULL)
	{
		if(!isBST(root->left))
		{
			return 0;
		}
		if(prev!=NULL && root->data<=prev->data)
		{
			return 0;
		}
		prev=root;
		return isBST(root->right);
	}
	else return 1;
}
int search(node *root, int key)
{
	if(root==NULL)
	{
		return NULL;
		
	}
	while(root!=NULL)
	{
		if(root->data==key)
		{
			return root->data;
		}
		else if(key<root->data)
		{
			root=root->left;
		}
		else
		root=root->right;
	}
	return NULL;
}
void insert(node *root, int key)
{
	 node *prev=NULL;
	if(root==NULL)
	{
		return;
		
	}
	while(root!=NULL)
	{
		prev=root;
		if(root->data==key)
		{
			cout<<"Cant be inserted as element is aready present"<<endl;
					}
		else if(key<root->data)
		{
			root=root->left;
		}
		else
		root=root->right;
	}
	//creating new node to be inserted as node is not being searched
	node *newnode=createnode(key);
	if(key<prev->data)
	{
		 prev->left=newnode;
	}
	else
	prev->right=newnode;
}
node* inorderpredecessor(node *root)
{
	root=root->left;// as inorderpredessor is right most child of left subtree
	while(root->right!=NULL)
  {
  	root=root->right;
  	
  }
  return root;
}
node * deleten(node *root,int value)
{
	node *ipre;
	if(root==NULL)
	{
		return NULL;
	}
	//basically it will execute when a leaf node is found and then we are freeing that node
	if(root->left==NULL && root->right==NULL)
	{
		delete root;
		return NULL;
	}
	//searching for the node
	if(value<root->data)
	{
		root->left=deleten(root->left,value);
	}
	else if(value>root->data)
	{
		root->right=deleten(root->right,value);
	}
	else//node found
	{
		ipre=inorderpredecessor(root);
		root->data=ipre->data;//replacing the node to be deleted with its inorder predecessor
		root->left=deleten(root->left,ipre->data);//calling function recursively after replaiin till we find any leaf node
	}
	return root;
}
int main()
{

node *p=createnode(5);
node *p1=createnode(3);
node *p2=createnode(6);
node *p3=createnode(1);
node *p4=createnode(4);
p->left=p1;
p->right=p2;
p1->left=p3;
p1->right=p4;
//inorder(p);
//cout<<"found"<<search(p,3);
insert(p,7);
//inorder(p);
deleten(p,3);
inorder(p);
return 0;

}

