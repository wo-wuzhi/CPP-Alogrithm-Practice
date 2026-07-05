#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct arr{
    ll a[2][2];
};

arr ch(arr m,arr n,ll k){
    arr x;
    x.a[0][0]=(m.a[0][0]*n.a[0][0]+m.a[0][1]*n.a[1][0])%k;
    x.a[0][1]=(m.a[0][0]*n.a[0][1]+m.a[0][1]*n.a[1][1])%k;
    x.a[1][0]=(m.a[1][0]*n.a[0][0]+m.a[1][1]*n.a[1][0])%k;
    x.a[1][1]=(m.a[1][0]*n.a[0][1]+m.a[1][1]*n.a[1][1])%k;
    return x;
}

ll solve(ll n,ll k){
    if(k==1) return 0;
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 1;
    ll ans;
    arr tp,bs;
    tp.a[0][0]=1;bs.a[0][0]=1;
    tp.a[0][1]=1;bs.a[0][1]=0;
    tp.a[1][0]=1;bs.a[1][0]=0;
    tp.a[1][1]=0;bs.a[1][1]=1;
    n-=2;
    while(n>0){
        if(n&1) bs=ch(tp,bs,k);
        tp=ch(tp,tp,k);
        n>>=1;
    }
    return (bs.a[0][0]+bs.a[0][1])%k;
}


int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        ll q,k;
        cin>>q>>k;
        while(q>0){
            q--;
            ll n;
            cin>>n;
            cout<<solve(n,k)<<endl;
        }
    }
}