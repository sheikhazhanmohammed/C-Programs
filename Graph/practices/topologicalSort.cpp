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

    void dfsHepler(T src, map<T,bool>&visit, list<T> &ordering){
        visit[src] = true;
        for(auto a: adjList[src]){
            if(visit[a] != true)
                dfsHepler(a, visit, ordering);
        }
        ordering.push_front(src);
    }

    void topo(){
        map<T, bool> visited;
        list<T> ordering;

        for(auto i: adjList){
            T node = i.first;
            if(!visited[node]){
                dfsHepler(node, visited, ordering);
            }
        }

        for(T element : ordering){
            cout<<element<<"-->";
        }
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    Graph<string> g;
    g.addEdg("English","ProgrammingLogic");
    g.addEdg("Maths","Programming Logic");
    g.addEdg("Programming Logic","HTML");
    g.addEdg("Programming Logic","Python");
    g.addEdg("Programming Logic","Java");
    g.addEdg("Programming Logic","JS");
    g.addEdg("Python","WebDev");
    g.addEdg("HTML","CSS");
    g.addEdg("CSS","JS");
    g.addEdg("JS","WebDev");
    g.addEdg("Java","WebDev");
    g.addEdg("Python","WebDev");
    g.topo();  
    return 0;
}