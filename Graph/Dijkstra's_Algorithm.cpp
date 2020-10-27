#include<bits/stdc++.h>
using namespace std;
#define lli long long 
template<typename T>

class Graph{
    map<T, list<pair<T, int>>> adList;
    public:
    void addEdge(T u, T v, int dist, bool bidir=true){
        adList[u].push_back(make_pair(v, dist));
        if(bidir){
            adList[v].push_back(make_pair(u, dist));
        }
    }

    map<T , int > dijaktra(T src){
        map<T , int > dist;

        for(auto j:adList){
            dist[j.first] = INT_MAX;
        }

        set<pair<int, T>> s;
        dist[src] = 0;
        s.insert({0, src});

        while(!s.empty()){

            auto p = *(s.begin());

            T node = p.second;

            lli nodeDist = p.first;
            s.erase(s.begin());

            for(auto childPair : adList[node]){
                if(nodeDist + childPair.second < dist[childPair.first]){
                    T dest = childPair.first;

                    auto f = s.find({dist[dest], dest});
                    if(f != s.end()){
                        s.erase(f);
                    }

                    dist[dest] = nodeDist + childPair.second;
                    s.insert({dist[dest] , dest});
                }
            }
        }
        return dist;
    }
};

int main(){
    lli t;
    cin>>t;
    while(t--){
        lli n,m;
        cin>>n>>m;
        Graph<int> g;
        for(int i=0; i<m; i++){
            lli a,b,c;
            cin>>a>>b>>c;
            g.addEdge(a-1, b-1, c);
        }
        lli s;
        cin>>s;
        map<int, int> ma = g.dijaktra(s-1);
        for(auto it :ma){
            if(it.second == INT_MAX){
                cout<<-1<<" ";
            }else if(it.second == 0){
                continue;
            }else{
                cout<<it.second<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}