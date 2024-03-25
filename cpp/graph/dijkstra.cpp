#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;


using P = pair<ll,ll>;

struct Edge {
    ll to,cost;
};

vector<ll> dijkstra(vector<vector<Edge>> &G, ll s) {
    ll N = G.size();
    vector<ll> dist(N, 1ll<<60);
    priority_queue<P, vector<P>, greater<P>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    dist[s] = 0;
    pq.emplace(dist[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        ll v = p.second;
        if (dist[v] < p.first) {  // 最短距離で無ければ無視
            continue;
        }
        for (Edge e : G[v]) {
            if (dist[e.to] > dist[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
                dist[e.to] = dist[v] + e.cost;
                pq.emplace(dist[e.to], e.to);
            }
        }
    }
    return dist;
}