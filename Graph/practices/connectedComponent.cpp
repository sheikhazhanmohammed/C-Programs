#include<bits/stdc++.h>
using namespace std;
#define lli long long 
#define t int t ; cin>>t; while(t--)
#define what(x) cerr << #x << '=' << x<<endl;

class Graph(){
    map<lli, lli> adjList;
    void addEdj(lli u, lli v){
        adjList[u] = v;
        addEdj[v] = u;
    }

    void dfsHepler(lli src, map<lli,bool>&visit){
        visit[src] = true;
        for(auto a: adjList[src]){
            if(visit[a] != true)
            dfsHepler(a, visit);
        }
    }
    lli dfs(lli src, lli n){
        map<lli , bool> visited;
        lli comp = 1;
        dfsHepler(src, visited);
        for( auto k: adjList){
            lli a = k.first;
            if(!visited[a]){
                dfsHepler(a, visited);
                comp++;
            }
        }
        return comp;
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    t
    return 0;
}       