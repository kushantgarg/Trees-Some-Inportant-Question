#include<iostream>
#include<stdlib.h>
#include<stack>
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
 void preorder(node *root)
 {
 	node *ptr=root;
 	stack<node*>s;
 	s.push(NULL);
 	while(ptr!=NULL || !s.empty())
 	{
 		while(ptr!=NULL)
 		{
 			cout<<ptr->data;
 			if(ptr->right!=NULL)
 			{
 				s.push(ptr->right);
			 }
			 ptr=ptr->left;
		 }
		 // as let child is NULL
		 if(!s.empty())
		 {
		 	ptr=s.top();
		 	s.pop();
		 }
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
//utility funciton to search for a node in a binary search tree
 node * search(node *root,int key)
 {
 	if(root==NULL)
 	{
 		return NULL;
	 }
 if(key==root->data){
        return root;
    }
    else if(key<root->data){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
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

     node* n = search(p, 6);
    if(n!=NULL){
    printf("Found: %d", n->data);
    }
    else{
        printf("Element not found");
    }
    return 0;
    
}

