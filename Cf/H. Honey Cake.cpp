#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll w,h,d,n,cnt=0;
    cin>>w>>h>>d>>n;
    if(n==1){cout<<0<<' '<<0<<' '<<0<<endl;return 0;}
    vector<ll>s;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0)s.push_back(i);
        if(i!=n/i)s.push_back(n/i);
    }
    sort(s.begin(),s.end());
    for(auto a:s){
        if(a>w||w%a!=0) continue;
        ll n1=n/a;
        if(h*d<n1) continue;
        for(ll i=1;i*i<=n1;i++){
            if(n1%i!=0) continue;
            ll b1=i;
            ll b2=n1/b1;
            for(auto it:{b1,b2}){
                if(it>h||h%it!=0)continue;
                ll c=n1/it;
                if(c<=d&&d%c==0){
                    cout<<a-1<<' '<<it-1<<' '<<c-1<<endl;
                    return 0;
                }
            }
            
        }
    }
    cout<<-1<<endl;
    return 0;
}