#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,t=0,st=0,p=0;
    cin>>n;
    vector<int>a(n);
    for(auto&it:a) cin>>it;
    for(int i=0;i<n-1;i++){
        if(a[i]<a[i+1]) 
        {
            t=i+1;
            st=t;
            break;
        }
    }
    for(int i=t;i<n;i++){
        if(a[i]>a[t]) t=i;
    }
    for(int i=st;i>=0;i--){
        if(a[i]>a[t]) {st=i+1;break;}
        else st=i;
    }
    reverse(a.begin()+st,a.begin()+t+1);
    for(auto&it:a) cout<<it<<' ';
    cout<<endl;
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