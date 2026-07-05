#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,k,cnt=0,ma=-1,ch=-1;
    cin>>n>>k;
    vector<int>a(n);
    map<int,int>mp;
    for(int i=0;i<n;i++) {cin>>a[i];mp[a[i]]++;ma=max(ma,a[i]);}
    for(int i=0;i<=ma;i++){
        if(mp[i]==0){ch=-ch;cout<<i<<endl;return;}
        cnt++;
        if(cnt==k){ch=-ch;cout<<i<<endl;return;}
    }
    if(ch<0)cout<<ma+1<<endl;
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