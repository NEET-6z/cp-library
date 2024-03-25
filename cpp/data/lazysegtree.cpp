#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

template<typename S, S (*op)(S, S), S (*e)(), typename F, S (*mapping)(F f,S x),F (*composition)(F f, F g), F (*id)()>
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

        lazy.resize(N,id());
    }

    S get(int idx){
        return A[N/2+idx];
    }

    void set(int idx,S x){
        int i = N/2+idx;
        A[i] = x;
        while(i>1){
            int p = i/2;
            A[p] = op(A[p*2],A[p*2+1]);
            i = p;
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
            
            A[idx*2] = mapping(lazy[idx],A[idx*2]);
            lazy[idx*2] = composition(lazy[idx*2],lazy[idx]);
            A[idx*2+1] = mapping(lazy[idx],A[idx*2+1]);
            lazy[idx*2+1] = composition(lazy[idx*2+1],lazy[idx]);

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

    void apply(int l,int r, F x){
        auto f = [&](auto f,int a,int b,int idx,int wl,int wr) -> void {

            if(idx>=N/2) return A[idx];
            int mid = (wl+wr)/2;
            
            int l1 = min(mid,a);
            int r1 = min(mid,b);
            int l2 = max(mid,a);
            int r2 = max(mid,b);
            // cout << a << " " << b << " " << idx << " " << wl << " " << wr << " " << l1 << " " << r1 << " " << l2 << " " << r2 << endl;

            A[idx*2] = mapping(lazy[idx],A[idx*2]);
            lazy[idx*2] = composition(lazy[idx*2],lazy[idx]);
            A[idx*2+1] = mapping(lazy[idx],A[idx*2+1]);
            lazy[idx*2+1] = composition(lazy[idx*2+1],lazy[idx]);
            
            if(r1-l1==(wr-wl)/2) {}
            else if(l1!=mid){
                f(f,l1,r1,idx*2,wl,mid);
            }
            if(r2-l2==(wr-wl)/2) {}
            else if(r2!=mid){
                f(f,l2,r2,idx*2+1,mid,wr);
            }
        };

        return f(f,l,r,1,0,N/2);
    }

private:
    int N;
    vector<S> A;
    vector<F> lazy;
};
