#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,ans=0,sum=0;
    cin>>n;
    vector<ll>b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
        sum+=b[i];
    }
    sort(b.begin(),b.end());
    auto it=upper_bound(b.begin(),b.end(),0);
   cout<<min(b.end()-it,sum-n+1)<<endl;
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