#include<bits/stdc++.h>
using namespace std;
#define lli long long 
#define t int t ; cin>>t; while(t--)
#define what(x) cerr << #x << '=' << x<<endl;
vector<lli> len;

class Graph{
    map<lli, list<lli>> adjlist;
    public:
    void addEdge(lli u, lli v, bool bidir=true){
        adjlist[u].push_back(v);
        if(bidir){
            adjlist[v].push_back(u);
        }
    }
    void dfspath(lli node, map<lli,bool>&visit, lli &count){
        visit[node]=true;
        count++;
        for(auto j:adjlist[node]){
            if(!visit[j]){
                dfspath(j,visit, count);
            }
        }
    }

    lli dfs(lli src, lli N){
        map<lli,bool> visited;
        lli count = 0;
        lli Total_ways=(N*(N-1))/2;
        dfspath(src, visited ,count);
        Total_ways-=(count*(count-1))/2;
        for(auto i:adjlist){
            lli city = i.first;
             count = 0;
            if(!visited[city]){
                dfspath(city, visited, count);
            }
            Total_ways-=(count*(count-1))/2;
        }
        return Total_ways;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli n,m;
    cin>>n>>m;
    Graph g;
    for(int i=0; i<m; i++){
        lli a,b;
        cin>>a>>b;
        g.addEdge(a,b);
    }
    cout<<g.dfs(0,n)<<endl;
    
    return 0;
}