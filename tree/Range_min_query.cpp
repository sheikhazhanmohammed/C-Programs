//Range Minimum Query using Segment Trees
//We build a tree in which each node stores the min value of its children denoting the smallest value in a particular range
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void buildTree(int *a,int s,int e,int *tree,int index){
  //Leaf Node
  if(s==e){
    tree[index]=a[s];
    return ;
  }

  int mid=(s+e)/2;
  buildTree(a,s,mid,tree,index*2);
  buildTree(a,mid+1,e,tree,index*2+1);
  tree[index]=min(tree[2*index],tree[2*index+1]);
  return ;
}

void updateNode(int *tree,int ss,int se,int i,int inc,int index){
  //Out of bounds
  if(i<ss || i>se)
  return ;

  //Leaf node
  if(ss==se){
    tree[index]+=inc;
    return;
  }

  int mid=(ss+se)/2;
  updateNode(tree,ss,mid,i,inc,index*2);
  updateNode(tree,mid+1,se,i,inc,index*2+1);
  tree[index]=min(tree[2*index],tree[2*index+1]);
  return;
}

void updateRange(int *tree,int ss,int se,int l,int r,int inc,int index){
  //Out of bounds
  if(r<ss || l>se)
  return;

  if(ss==se){
    tree[index]+=inc;
    return;
  }

  int mid=(ss+se)/2;
  updateRange(tree,ss,mid,l,r,inc,index*2);
  updateRange(tree,mid+1,se,l,r,inc,index*2+1);
  tree[index]=min(tree[2*index],tree[2*index+1]);
  return;
}

int query(int *tree,int ss,int se,int l,int r,int index){
  //Complete overlap
  if(l<=ss && r>=se)
  return tree[index];

  //No overlap
  if(r<ss || l>se)
  return INT_MAX;

  //Partial overlap
  int mid=(ss+se)/2;
  int left=query(tree,ss,mid,l,r,index*2);
  int right=query(tree,mid+1,se,l,r,index*2+1);
  return min(left,right);
}

int main(){
  int a[]={1,3,2,-5,6,4};
  int n=sizeof(a)/sizeof(a[0]);
  int *tree = new int[4*n+1];
  buildTree(a,0,n-1,tree,1);

  //Print the tree
  for(int i=1;i<13;i++){
    //cout<<tree[i]<<" ";
  }
  updateNode(tree,0,n-1,2,10,1);
  updateRange(tree,0,n-1,2,3,10,1);

  int l,r;
  cin>>l>>r;
  query(tree,0,n-1,l,r,1);

  return 0;
}
