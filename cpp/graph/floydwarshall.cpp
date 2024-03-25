#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

void floydwarshall(vector<vector<ll>> &dp){
    ll N = dp.size();
    rep(k,N){
        rep(i,N){
            rep(j,N){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
}


vector<vector<ll>> build(ll N){
    vector<vector<ll>> G(N,vector<ll>(N,2e18));
    rep(i,N) G[i][i] = 0;
    return G;
}

int main(){
    
}