#include<iostream>
using namespace std;
int tree[10];//declaring the tree size that it can hold max of 10 elements
int root(int data)
{
	if(tree[0]!=0)
	{
		cout<<"Root is already there"<<endl;
		
	}
	else
	tree[0]=data;
	return 0;
}
int setleft(int data,int parent)
{
	if(tree[parent]==0)
	{
		cout<<"NO elemnt inserted as parent is not found at"<<2*parent+1<<endl;
		
	}
	else
	{
		tree[2*parent+1]=data;
	}
	return 0;
}
int setright(int data,int parent)
{
	if(tree[parent]==0)
	{
		cout<<"NO elemnt inserted as parent is not found at"<<2*parent+2<<endl;
		
	}
	else
	{
		tree[2*parent+2]=data;
	}
	return 0;
}
int print_tree() {
  cout << "\n";
  for (int i = 0; i < 10; i++) {
    if (tree[i]!=0)
      cout << tree[i]<<" ";
    else
      cout << "-";
  }
  return 0;
}
int main()
{
	root(10);
	setleft(9,0);
	setright(8,0);
	print_tree();
}
