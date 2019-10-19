#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define endl "\n"
lli lca(lli *tree, lli root, lli n1, lli n2){
	if(tree[root] == 0) return 0;

	if(tree[root] == n1 || tree[root]==n2){
		return tree[root];
	}

	lli left = lca(tree, 2*root, n1, n2);
	lli right = lca(tree, 2*root+1, n1, n2);

	if(left != 0 && right != 0){
		return tree[root];
	}
	if(left == 0){
		return right;
	}else{
		return left;
	}
}
void BuildTree(lli *arr, lli s, lli e, lli *tree, lli index){
	if(s==e){
		tree[index] = arr[s];
		return;
	}
	lli mid = (s+e)/2;
	BuildTree(arr,s,mid, tree, 2*index); // FOR LEFT NODE 
    BuildTree(arr,mid+1,e,tree,2*index+1);
	tree[index] = min(tree[2*index],tree[2*index+1]);
	return;
}

lli  B_BST(lli *arr,lli start, lli end){
	if(start>end) return 0;
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	lli n;
	cin>>n;
	lli a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	lli *tree = new lli[4*n+1];
	BuildTree(a,0,n-1,tree,1);
	for(int j=0; j<n; j++){
		cout<<tree[j]<<" ";
	}
	lli n1,n2;
	cin>>n1>>n2;
	cout<<lca(tree,1,n1,n2)<<" LCA";
	return 0;
}