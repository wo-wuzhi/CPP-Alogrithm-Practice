#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll x,m,cnt=0;
    cin>>x>>m;
    ll k=0,y=0;
    while(k<=x){
        y=k^x;
        if(y<=m&&y>=1&&y!=x&&(y%k==0||x%k==0)){cnt++;}
        k++;
    }
    cout<<cnt<<endl;
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