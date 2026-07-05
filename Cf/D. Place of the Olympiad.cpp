#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll m,n,sum,tp=0;
    cin>>m>>n>>sum;
    if(sum<=m){cout<<1<<endl;return;}
    if(sum%m!=0) tp=sum/m+1;
    else tp=sum/m;
    if(2*tp-1<=n){cout<<1<<endl;return;}
    ll p=n-tp;
    if(tp%(p+1)!=0) cout<<tp/(p+1)+1<<endl;
    else cout<<tp/(p+1)<<endl;
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