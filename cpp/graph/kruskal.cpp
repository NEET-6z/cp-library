#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

#include "../data/dsu.cpp"

struct Edge {
    ll a,b,cost;

    bool operator<(const Edge& o) const {
        return cost < o.cost;
    }
};

ll kruskal(int N,vector<Edge> es) {
    sort(es.begin(), es.end());

    dsu uf(N);
    int min_cost = 0;

    for(Edge &e:es){
        if(!uf.same(e.a,e.b)){
            min_cost += e.cost;
            uf.merge(e.a,e.b);
        }
    }

    return min_cost;
}


int main(){
    int n,m;
    cin >> n >> m;
    vector<Edge> es(m);
    rep(i,m) cin >> es[i].a >> es[i].b >> es[i].cost;
    cout << kruskal(n,es) << endl;
}