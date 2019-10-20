#include<iostream>
#include<queue>
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
class HeightAndDiameter
{
  public:
    int height;
    int diameter;
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
int findheight(Tree* root)
{
  if(root==NULL)
  {
    return 0;
  }
  int leftchildheight=findheight(root->left);
  int rightchildheight=findheight(root->right);
  int h=max(leftchildheight,rightchildheight)+1;
  return h;
}
HeightAndDiameter fastdiameter(Tree* root)
{
  HeightAndDiameter h;
  if(root==NULL)
  {
    h.height=0;
    h.diameter=0;
    return h;
  }
  HeightAndDiameter left=fastdiameter(root->left);
  HeightAndDiameter right=fastdiameter(root->right);
  h.height=max(left.height,right.height)+1;
  int option1=left.height+right.height;
  int option2=left.diameter;
  int option3=right.diameter;
  h.diameter=max(option1,max(option2,option3));
  return h;
}
int finddiamter(Tree* root)
{
  if(root==NULL)
  {
    return 0;
  }
  int rootheight=findheight(root->left)+findheight(root->right);
  int leftchildheight=finddiamter(root->left);
  int rightchildheight=finddiamter(root->right);
  int dia=max(rootheight,max(leftchildheight,rightchildheight));
  return dia;
}
//level order traversal, level order printing
void LevelOrderPrinting(Tree* root)
{
  queue<Tree*>q;
  q.push(root);
  q.push(NULL);
  while(!q.empty())
  {
    Tree* n=q.front();
    q.pop();
    if(n==NULL)
    {
      cout<<endl;
      if(!q.empty())
      {
        q.push(NULL);
      }
    }
    else
    {
      cout<<n->data<<" ";
      if(n->left)
        q.push(n->left);
      if(n->right)
        q.push(n->right);
    }
  }
}
//creating mirror image of a Tree
void MirrorOfTree(Tree* &root)
{
  if(root==NULL)
  {
    return;
  }
  swap(root->left,root->right);
  MirrorOfTree(root->left);
  MirrorOfTree(root->right);
}
main()
{
  Tree* root=createtree();
  MirrorOfTree(root);
  LevelOrderPrinting(root);
}
