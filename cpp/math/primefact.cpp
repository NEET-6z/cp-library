#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

vector<pair<ll,ll>> primefact(ll n){
    vector<pair<ll,ll>> primes;
    for(int i = 2;i*i<=n;i++){
        int cnt = 0;
        while(n%i==0){
            n/=i;
            cnt++;
        }
        if(cnt>0){
            primes.push_back(make_pair(i,cnt));
        }
    }
    if(n>1) primes.push_back(make_pair(n,1));
    return primes;
}

