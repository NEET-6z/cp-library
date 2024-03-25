#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int lis(vector<int> a){
    int n = a.size();

    vector<int> dp(n+1,1e9);
    dp[0] = -1;
    rep(i,n){
        int id = lower_bound(dp.begin(),dp.end(),a[i])-dp.begin();
        dp[id] = min(dp[id],a[i]);
    }
    int res = lower_bound(dp.begin(),dp.end(),1e9)-dp.begin()-1;
    return res;
}