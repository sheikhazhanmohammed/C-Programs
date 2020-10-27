#include<bits/stdc++.h>
using namespace std;
#define lli long long 

class Graph{
    lli V;
    map<lli,list<lli>> adjList;
    public:
    Graph(lli v){
        V = v;
        // adjList = new map<lli,list<lli>>[V];
    }

    void addEdge(lli u, lli v, bool biDir = true){
        adjList[u].push_back(v);
        if(biDir){
            adjList[v].push_back(u);
        }
    }
};

int main(){
    
    return 0;
}