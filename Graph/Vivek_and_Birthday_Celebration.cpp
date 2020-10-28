#include<bits/stdc++.h>
using namespace std;
#define lli long long int
lli n;
class Graph{
    map<lli, lli> adjList;
    void addEdg(lli u, lli v){
        adjList[u] = v;
    }

    void bfs(lli src){
        vector<bool> visited;
        for(int i=0; i<n; i++) visited[i] = false; 
        queue<lli> q;
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            lli f = q.front();
            q.pop();
            for(auto x : adjList[f]){
                if(!visited[x]){
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
        lli count = 0;
        for(int i=0; i<visited.seze(); i++){
            if(visited[i]){
                count++;
            }
        }
        cout<<count<<endl;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli d; cin>>n>>d;
    Graph g;
    for(int i=0; i<d; i++){
        lli a,b; cin>>a>>b;
        g.addEdg(a,b);
    }
    bfs(1);
    return 0;
}