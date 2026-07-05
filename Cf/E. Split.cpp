#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,k;
    ll ans=0;
    cin>>n>>k;
    vector<int>a(n+1);
    map<int,int>b;
    for(int i=1;i<=n;i++){ 
        cin>>a[i];
        b[a[i]]++;
    }
    for(auto it=b.begin();it!=b.end();it++){
        if(it->second%k!=0){cout<<0<<endl;return;}
    }
    int l=1,r=1,pcnt=0;
    map<int,int>tp;
    for(;r<=n;r++){
        tp[a[r]]++;
        while(tp[a[r]]>b[a[r]]/k){
            tp[a[l]]--;
            l++;
        }
        ans+=r-l+1;
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