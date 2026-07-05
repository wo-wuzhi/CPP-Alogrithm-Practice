#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,ct=0;
    cin>>n;
    map<int,int>a;
    for(int i=0;i<n*n;i++){
        int tp;
        cin>>tp;
        a[tp]++;
    }
    for(auto it=a.begin();it!=a.end();it++){
        ct=max(ct,it->second);
    }
    if(ct<=(n)*(n-1)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return;
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