#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

vector<int> bfs(vector<vector<int>> &G,ll s){
    int N = G.size();
    vector<int> dist(N,1e9);
    dist[s] = 0;
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int x:G[p]){
            if(dist[x]!=1e18) continue;
            dist[x] = dist[p]+1;
            q.push(x);
        }
    }

    return dist;
}



vector<vector<int>> makegridg(vector<vector<bool>> grid){
    int H = grid.size();
    int W = grid[0].size();
    vector<vector<int>> G(H*W);
    rep(i,H){
        rep(j,W){
            if(i!=0) {
                G[i*W+j].push_back(i*W+j-W);
                G[i*W+j-W].push_back(i*W+j);
            }
            if(j!=0){
                G[i*W+j].push_back(i*W+j-1);
                G[i*W+j-1].push_back(i*W+j);
            }
        }
    }
    return G;
}