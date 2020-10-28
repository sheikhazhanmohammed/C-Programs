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