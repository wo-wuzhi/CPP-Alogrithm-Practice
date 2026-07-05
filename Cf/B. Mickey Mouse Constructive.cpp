#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int get(int a){
    int x=abs(a);
    ll res=0;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            res++;
            if(x/i!=i) res++;
        }
    }
    return res;
}

void solve(){
    int x,y;
    cin>>x>>y;
    ll ans=get(x-y)%676767677;
    if(x-y==0) cout<<1<<'\n';
    else cout<<ans<<'\n';
    while(x>0){
        x--;
        cout<<1<<' ';
    }
    while(y>0){
        y--;
        cout<<-1<<' ';
    }
    cout<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        solve();
    }
    return 0;
}