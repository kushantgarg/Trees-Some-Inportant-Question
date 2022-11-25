#include<iostream>
#include<stdio.h>
using namespace std;
class Node{
	public:
		int data;
		Node* left;
		Node *right;
		//constructor to initisile each and every node
		Node(int key)
		{
			data=key;
			left=right=NULL;
		}
};
int height(Node *root)
{
	//base case
	if(root==NULL)
	{
		return 0;//that is now no further node exit we reach  our leaf node
	}
	// recur for left and write subtree 
	return 1+max(height(root->left),height(root->right));
}
int main()
{
	Node * root=new Node(15);
	root->left=new Node(10);
	// this is anamyous calling of consructor
	root->right=new Node(20);
	  root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
// so basically our tree got creatd now we will call our recursive function to 
// to find the height of binary tree
cout<<"The height of this binary tree is"<<height(root); 
	return 0;
}
