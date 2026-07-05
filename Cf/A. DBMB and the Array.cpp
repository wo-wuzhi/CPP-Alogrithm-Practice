#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,s,x,sum=0;
    cin>>n>>s>>x;
    vector<int>a(n);
    for(auto&it:a){
        cin>>it;
        sum+=it;
    }
    if(sum==s) cout<<"YES"<<endl;
    else if(sum>s) cout<<"NO"<<endl;
    else{
        if((s-sum)%x==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
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