#include<bits/stdc++.h>
using namespace std;
#define lli long long 
#define t int t ; cin>>t; while(t--)
#define what(x) cerr << #x << '=' << x<<endl;

class Graph{
    map<lli, list<pair<lli,lli>>> adjlist;

    void addEdg(lli u, lli v, lli dist){
        adjlist[u].push_back({v,dist});
        adjlist[u].push_back({v,dist});
    }

    map<lli , lli > dij(lli src){
        map<lli, lli> Mdist;

        for(auto i : adjlist){
            Mdist[i.first] = INTMAX_MAX;
        }
        set<pair<lli ,lli>> s;
        Mdist[src] = 0;
        s.insert({0, src});
        while(!s.empty()){
            auto F = *(s.begin());
            lli Fdist = F.first;
            lli node  = F.second;
            for(auto child : adjlist[node]){
                if(Fdist+child.second < Mdist[child.first]){
                    lli dest = child.second;

                    auto find = s.find({Mdist[dest], dest});
                    if(find != s.end()){
                        s.erase(find);
                    }
                    Mdist[dest] = Fdist+child.second ;
                    s.insert({Fdist+child.second , dest});
                }
            }
        }
        return Mdist; 
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    t
    return 0;
}