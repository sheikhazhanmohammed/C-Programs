#include<bits/stdc++.h>
using namespace std;
#define lli long long 

class Graph{
    map<lli, list<lli>> adjList;
    public:
    void addEdge(int u, int v, bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    lli bfs(lli src, lli dest){
        lli distance[102];
        for(int i=0; i<=100; i++){
            distance[i] = INT_MAX;
        }
        distance[src] = 0;
        vector<int> parent;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            lli front = q.front();
            q.pop();
            for(auto it = adjList[front].begin(); it!=adjList[front].end(); it++){
                if(distance[*it] == INT_MAX){
                    q.push(*it);
                    distance[*it] = distance[front] + 1;
                }
            }
        }
        if(distance[dest] == INT_MAX){
            return -1;
        }else{
            return distance[dest];
        }
    }
};

int main(){
    lli t;
    cin>>t;
    while(t--){
        lli n,m;
        cin>>n;
        lli edg[202] = {0};
        lli a,b;
        for(int i=0; i<n; i++){
            cin>>a>>b;
            edg[a] = b;
        }
        cin>>m;
        for(int i=0; i<m; i++){
            cin>>a>>b;
            edg[a] = b;
        }
        lli v;
        Graph G;
        for(int i=1; i<=100; i++){
            for(int j=1; j<=6; j++){
                if(edg[i+j]==0){
                    v = i+j;    
                }else{
                    v = edg[i+j];
                }
                G.addEdge(i , v, false);
            }
        }
        cout<<G.bfs(1,100)<<endl;
        
    }
    return 0;
}