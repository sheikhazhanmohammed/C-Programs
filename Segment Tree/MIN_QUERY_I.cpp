#include<bits/stdc++.h>
using namespace std;
#define lli long long 

void buildTree(lli *a, lli s, lli e, lli *tree, lli index){
    if(s == e){
        tree[index] = a[s];
        return ;
    }

    lli mid = (e+s)/2;
    buildTree(a,s,mid,tree,2*index);
    buildTree(a,mid+1,e,tree,2*index+1);
    tree[index] = min(tree[2*index], tree[2*index+1]);

    return ;
}

lli queryMin(lli *tree, lli ts, lli te, lli qs, lli qe, lli index){
    if(ts>=qs && te<=qe){
        return tree[index];
    }

    if(qs>te || qe<ts){
        return INT_MAX;
    }

    lli mid = (ts+te)/2;
    lli left = queryMin(tree,ts,mid,qs,qe,2*index);
    lli right = queryMin(tree,mid+1,te,qs,qe,2*index+1);
    return min(left , right);
}

void updateQueryRange(lli *tree, lli ts, lli te, lli l, lli r,lli inc, lli index){
    if(r<ts || l>te){
        return;
    }

    if(ts == te){
        tree[index] = inc;
        return;
    }

    lli mid = (ts+te)/2;
    updateQueryRange(tree, ts, mid,l,r,inc,2*index);
    updateQueryRange(tree, mid+1, te,l,r,inc,2*index+1);
    tree[index] = min(tree[2*index], tree[2*index+1]);
    return;
}

void updateQuery(lli *tree, lli ts, lli te, lli l,lli inc, lli index){
    if(l<ts || l>te){
        return;
    }

    if(ts == te){
        tree[index] += inc;
        return;
    }

    lli mid = (ts+te)/2;
    updateQuery(tree, ts, mid,l,inc,2*index);
    updateQuery(tree, mid+1, te,l,inc,2*index+1);
    tree[index] = min(tree[2*index], tree[2*index+1]);
    return;
}

int main(){
    lli n ,m ;
    cin>>n>>m;
    lli a[n];
    lli *tree = new lli[4*n+1];
    // lli tree[4*n+1];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    lli k,l,r;
    buildTree(a,0,n-1,tree,1);
    for(int i=0; i<m; i++){
        cin>>k>>l>>r;
        if(k==1){
            cout<<queryMin(tree,0,n-1,l-1,r-1,1)<<endl;
        }
        else{
            updateQuery(tree,0,n-1,l-1,r,1);
        }
        
    }
    return 0;
}

// LEETCODE SOLUTION SEEN 
class NumArray {
    struct SegmentTreeNode{
        int start;
        int end;
        int sum;
        SegmentTreeNode* left;
        SegmentTreeNode* right;
        SegmentTreeNode(int l, int r):start(l), end(r), sum(0), left(NULL), right(NULL){}
    };
    SegmentTreeNode* root;
    
    SegmentTreeNode* buildTree(vector<int>& nums, int start, int end){
        if(start > end) return NULL;
        SegmentTreeNode* p = new SegmentTreeNode(start, end);
        if(start == end){
            p->sum = nums[start];
        }
        else{
            int mid = start + (end - start) / 2;
            p->left = buildTree(nums, start, mid);
            p->right = buildTree(nums, mid + 1, end);
            p->sum = p->left->sum + p->right->sum;
        }
        return p;
    }
    
    void update(SegmentTreeNode* p, int i, int val){
        if(p->start == i && p->end == i){
            p->sum = val;
        }
        else{
            int mid = p->start + (p->end - p->start) / 2;
            if(i <= mid) update(p->left, i, val);
            else update(p->right, i, val);
            p->sum = p->left->sum + p->right->sum;
        }
    }
    
    int sumRange(SegmentTreeNode* p, int i, int j){
        if(p->start == i && p->end == j){
            return p->sum;
        }
        int mid = p->start + (p->end - p->start) / 2;
        if(j <= mid) 
            return sumRange(p->left, i, j);
        else if(i > mid) 
            return sumRange(p->right, i, j);
        else 
            return sumRange(p->left, i, mid) + sumRange(p->right, mid + 1, j);
    }
    
public:
    NumArray(vector<int> nums) {
        root = buildTree(nums, 0, nums.size() - 1);
    }
    
    void update(int i, int val) {
        update(root, i, val);
    }
    
    int sumRange(int i, int j) {
        return sumRange(root, i, j);
    }
};