#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

vector<bool> eratosthenes(int n){
    vector<bool> isprime(n+1,true);
    isprime[0] = isprime[1] = false;

    for(int i = 2;i*i<=n;i++){
        if(!isprime[i]) continue;
        rep(j,n/i-1){
            isprime[(j+2)*i] = false;
        }
    }

    return isprime;
}
