//A BST is a Binary Tree where left child is smaller than root and right child is greater than root
#include<iostream>
using namespace std;
class Tree
{
public:
  int data;
  Tree* left;
  Tree* right;

  Tree(int d)
  {
    data=d;
    left=NULL;
    right=NULL;
  }
};
Tree* createtree()
{
  int d;
  cin>>d;
  if(d==-1)
  {
    return NULL;
  }
  Tree* root= new Tree(d);
  cout<<"Enter left child of "<<d<<": ";
  root->left=createtree();
  cout<<"Enter right child of "<<d<<": ";
  root->right=createtree();

  return root;
}
bool isBST(Tree* root, int min=INT_MIN, int max=INT_MAX)
{
  if(!root)
    return true;
  if((min<=root->data && root->data<max) && isBST(root->left, min, root->data) && isBST(root->right, root->data+1,max))
    return true;
  else
    return false;

}
main()
{
  Tree* root=createtree();
  bool a=isBST(root);
  if(a)
    cout<<"Is a BST"<<endl;
  else
    cout<<"Not a BST"<<endl;
}
