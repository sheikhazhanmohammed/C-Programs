#include<bits/stdc++.h>
using namespace std;
#define lli long long 
#define t int t ; cin>>t; while(t--)
#define what(x) cerr << #x << '=' << x<<endl;

template<typename  T>
class Graph{
    map<T, list<T>> adjList;
    public:
    void addEdg(T u, T v){
        adjList[u].push_back(v);
    }

    bool isCyclic(T src){
        map<T, bool> visited;
        map<T, int> parent;
        queue<T> q;

        q.push(src);
        visited[src] = true;
        parent[src] = src;

        while(!q.empty()){
            T node = q.front();
            q.pop();

            for(T n : adjList[node]){
                if(visited[n] == true && parent[node]!= n){
                    return true;
                }else if(!visited[n]){
                    visited[n] = true;
                    parent[n] = node;
                    q.push(n);
                }
            }
        }
        return false;
    }
    

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    Graph<string> g;
    
    return 0;
}