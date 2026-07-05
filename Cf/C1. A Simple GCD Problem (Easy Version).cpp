#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll get(ll a,ll b){
    while(b!=0){
        ll tp=a%b;
        a=b;
        b=tp;
    }
    return a;
}

void solve(){
    ll n,cnt=0;
    cin>>n;
    vector<ll>a(n);
    vector<ll>b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<ll>c(n-1);
    for(int i=0;i<n-1;i++){
        c[i]=get(a[i],a[i+1]);
        if(c[i]<a[i]){
            if(i==0){
                cnt++;
                a[i]=c[i];
            }else{
                ll ch=get(c[i-1],c[i]);
                if(c[i-1]*c[i]/ch<a[i]){cnt++;a[i]=c[i-1]*c[i]/ch;}
            }
        }
    }
    if(a[n-1]>c[n-2]) cnt++;
    cout<<cnt<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        solve();
    }
}