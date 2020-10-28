#include<bits/stdc++.h>
using namespace std;
#define lli long long 

vector<lli> a(100005);
vector<lli> tree[400005];

void buildTree( lli s, lli e, lli index){
    if(s == e){
        tree[index].push_back(a[s]);
        return ;
    }

    lli mid = (e+s)/2;
    buildTree(s,mid,2*index);
    buildTree(mid+1,e,2*index+1);
    merge(tree[2*index].begin(), tree[2*index].end(),tree[2*index+1].begin() , tree[2*index+1].end(), back_inserter(tree[index]));

    return ;
}

lli queryK(lli ts, lli te, lli qs, lli qe, lli index,lli k){
    if(ts>=qs && te<=qe){
        lli len= tree[index].size(); 
        return len - (lower_bound(tree[index].begin(),tree[index].end(),k) - tree[index].begin());
    }

    if(qs>te || qe<ts){
        return 0;
    }

    lli mid = (ts+te)/2;
    lli left = queryK(ts,mid,qs,qe,2*index, k);
    lli right = queryK(mid+1,te,qs,qe,2*index+1, k);
    return (left+ right);
}


int main(){
    lli n ,m ;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    lli K,L,R;
    lli count =0;
    cin>>m;
    buildTree(0,n-1,1);
    while(m--){
      lli L,R,K;
      cin>>L>>R>>K;
      cout<<queryK(0,n-1,L-1,R-1,1,K)<<endl;
  }
    return 0;
}