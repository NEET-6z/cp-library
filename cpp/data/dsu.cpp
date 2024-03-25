#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

struct dsu{
    int N;
    vector<int> parent;

    dsu(int N):N(N),parent(N,-1) {}

    int leader(int x){
        if(parent[x]<0) return x;
        return parent[x] = leader(parent[x]);
    }

    void merge(int x,int y){
        int xp = leader(x);
        int yp = leader(y);
        if(xp==yp) return ;
        if(xp<yp) swap(xp,yp);
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }

    bool same(int x,int y){
        return leader(x)==leader(y);
    }

    vector<vector<int>> groups(){
        vector<vector<int>> a(N);
        rep(i,N) a[leader(parent[i])].push_back(i);
        vector<vector<int>> uni;
        rep(i,N) if(!a[i].empty()) uni.push_back(a[i]);

        return uni;
    }

};
