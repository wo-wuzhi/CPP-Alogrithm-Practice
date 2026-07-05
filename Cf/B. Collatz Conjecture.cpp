#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll x,k,y;
    cin>>x>>y>>k;
    if(y==1){cout<<0<<endl;return;}
    cout<<(((x%y+(k+1)%y)%y==0)?1:(x%y+k%y)%y)<<endl;
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