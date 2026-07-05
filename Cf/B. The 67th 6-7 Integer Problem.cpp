#include<bits/stdc++.h>
using namespace std;


void solve(){
    int ans=0;
    vector<int>a;
    for(int i=0;i<7;i++) {int x;cin>>x;a.push_back(x);}
    sort(a.begin(),a.end());
    for(int i=0;i<7;i++){
        if(i!=6) ans+=-a[i];
        else ans+=a[i];
    }
    cout<<ans<<endl;
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