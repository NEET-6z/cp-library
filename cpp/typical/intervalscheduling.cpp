#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int scheduling(vector<pair<int,int>> rl){
    int n = rl.size();

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    rep(i,n){
        pq.push(make_pair(rl[i].first,rl[i].second));
    }
    int now = 0;
    int cnt=0;
    rep(i,n){
        pair<int,int> p = pq.top();
        pq.pop();
        if(now>p.second) continue;
        now = p.first;
        cnt++;
    }

    return cnt;
}
