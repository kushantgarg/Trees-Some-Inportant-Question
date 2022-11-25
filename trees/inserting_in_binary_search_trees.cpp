#include<iostream>
#include<stdlib.h>
using namespace std;
class node{ public:
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
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
int isBST( node* root){
    static  node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
 void insert(node *root,int key)
 {
 	node*prev=NULL;//for pointing the current root 
	 if(root==NULL)
 	{
 		return ;
	 }
	 while(root!=NULL)
	 {
	 prev=root;
 if(key==root->data){
       cout<<"Cant be inserted as dupliccate is found"<<" ";
       return;
    }
    else if(key<root->data){
        root=root->left;
    }
    else{
        root=root->right;
    }
}
//creating the new node to insert
node *newnode=createnode(key);
if(key<prev->data)
{
	prev->left=newnode;
}
else
prev->right=newnode;
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

int main()
{
	   node *p = createnode(5);
     node *p1 = createnode(3);
     node *p2 = createnode(6);
     node *p3 = createnode(1);
    node *p4 = createnode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    insert(p,2);
    inorder(p);
    
     
    return 0;
}

