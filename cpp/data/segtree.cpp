#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

template<typename S, S (*op)(S, S), S (*e)()>
class segtree{
public:
    segtree(vector<S> v) {
        int n = v.size();
        int exponent = ceil(log2(n));
        N = pow(2, exponent+1);
        A.resize(N);
        rep(i,N/2){
            if(i<n) this->set(i,v[i]);
            else this->set(i,e());
        }

    }

    S get(int idx){
        return A[N/2+idx];
    }

    void set(int idx,S x){
        int id = N/2+idx;
        A[id] = x;
        while(id>1){
            int p = id/2;
            A[p] = op(A[p*2],A[p*2+1]);
            id = p;
        }

    }

    S prod(int l,int r){
        auto f = [&](auto f,int a,int b,int idx,int wl,int wr) -> S {

            if(idx>=N/2) return A[idx];
            int mid = (wl+wr)/2;
            S res = e();
            
            int l1 = min(mid,a);
            int r1 = min(mid,b);
            int l2 = max(mid,a);
            int r2 = max(mid,b);
            // cout << a << " " << b << " " << idx << " " << wl << " " << wr << " " << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
            
            if(r1-l1==(wr-wl)/2) res = op(res,A[idx*2]);
            else if(l1!=mid){
                res = op(res,f(f,l1,r1,idx*2,wl,mid));
            }
            if(r2-l2==(wr-wl)/2) res = op(res,A[idx*2+1]);
            else if(r2!=mid){
                res = op(res,f(f,l2,r2,idx*2+1,mid,wr));
            }
            return res;
        };

        return f(f,l,r,1,0,N/2);
    }

private:
    int N;
    vector<S> A;
};
