#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

const ll mod = 1242142124241289;
const ll base = 26;

ll N;
vector<ll> v(505050,0);
vector<ll> p(505050,1);

ll rolling(int l,int r){
    return (v[r]-p[r-l]*v[l]%mod+mod)%mod;
}

void build(){
    rep(i,N)v[i+1] = (v[i]*base+(25-0))%mod; //25-0のところ変えろ
    rep(i,N-1) p[i+1] = p[i]*base%mod;
}
