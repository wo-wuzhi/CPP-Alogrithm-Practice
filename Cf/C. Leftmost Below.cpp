#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin>>n;
    vector<ll>b(n);
    for(int i=0;i<n;i++) cin>>b[i];
    ll p=1,mi=b[0];
    for(int i=1;i<n;i++){
        if(b[i-1]>=b[i]) p=i;
        else break;
        mi=min(mi,b[i]);
    }
    if(p==n-1&&b[p-1]>b[p]){cout<<"YES"<<endl;return;}
    for(int i=p;i<n;i++){
        if(b[i-1]==1&&b[i]>b[i-1]){cout<<"NO"<<endl;return;}
        if(b[i]==b[i-1]) continue;
        if(b[i]>2*mi-1){cout<<"NO"<<endl;return;}
        mi=min(mi,b[i]);
    }
    cout<<"YES"<<endl;
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