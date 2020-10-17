// ----- In the name of ALLAH, the Most Gracious, the Most Merciful -----

#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define deb(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define memo(a,val) memset(a,val,sizeof(a))
#define NINJA ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(a) a.begin(),a.end()
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define dloop(i,n) for(int i=n-1;i>=0;i--)
#define iii tuple<int,int,int>
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define int long long
#define ld long double
#define pb push_back
#define endl "\n"
#define setbits __builtin_popcountll
#define mp map<int,int>
#define F first
#define S second
#define sz(v) (int)v.size()
#define mod 1000000007
#define inf (int)1e18

const int mxn = 1e5+10;
int tree[4*mxn],a[4*mxn],ans[4*mxn];

//Here making segment tree from l = 1 to r = max(a1,a2,a3...an) 
//Maximum LIS is tree[i] value.

int query(int l,int r, int i, int se,int ed){
	if(se>r or l>ed) return 0;

	if(l>=se and ed>=r) return tree[i];

	int m = (l+r)/2;

	int ans1 = query(l,m,2*i,se,ed);
	int ans2 = query(m+1,r,2*i+1,se,ed);

	return max(ans1,ans2);
}

void update(int l,int r, int i,int pos, int val){
	if(l==r){
		
		tree[i] = val;
		return;
	}

	int m = (l+r)/2;

	if(pos<=m) update(l,m,2*i,pos,val);
	else update(m+1,r,2*i+1,pos,val);

	tree[i] = max(tree[2*i],tree[2*i+1]);
}

int32_t main(){
	NINJA;

	int n; cin >> n;

	for1(i,n) cin >> a[i];	

	int res = 0;

	for1(i,n){

		// debug() << "press";
		

		ans[a[i]] = query(1,n,1,1,a[i])+1;  //+1 because, if we found nothing in range 1 to a[i]-1 then 1 for himself.

		// debug() << "press";

		update(1,n,1,a[i],ans[a[i]]); // updating from l=1 to r=a[i] with value = ans[a[i]]

		res=max(res,ans[a[i]]); //taking maximum at each step.
	}

	cout << res << endl;
	
	return 0;
}
