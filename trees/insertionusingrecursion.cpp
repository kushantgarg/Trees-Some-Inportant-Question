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
 node* insert(node *root,int key)
 {
 	if(root==NULL)
 	{
 		return createnode(key);
	 }
	 if(key==root->data)
	 {
	 	cout<<"Cant be inserted" ;
	 	return root;
	 }
	 if(key<root->data)
	 {
	 	root->left=insert(root->left,key);
	 }
	else if(key>root->data)
	 {
	 	root->right=insert(root->right,key);
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
    insert(p,5);
    inorder(p);
    //preorder(p);
    
     
    return 0;
}

