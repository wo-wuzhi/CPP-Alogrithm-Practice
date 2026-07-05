#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n,0);
    unordered_map<int,int>m;
    for(int i=0;i<n;i++) {int x;cin>>x;m[x]=i;}
    for(int i=0;i<n;i++){ cin>>a[i];}
    for(int i=1;i<n;i++){
        if(m[a[i]]<m[a[i-1]]){cout<<"NO"<<endl;return;}
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
}