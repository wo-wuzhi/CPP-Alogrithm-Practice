#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,cnt=0,p=0;
    cin>>n;
    cnt+=n+n/2+n/2+n/3+n/3;
    cout<<cnt<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        solve();
    }
}