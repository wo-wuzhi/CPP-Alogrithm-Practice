#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,m,s;
    cin>>n>>m>>s;
    long long ans=s;
    vector<ll>cost(n+1);
    for(int i=0;i<n;i++) cin>>cost[i+1];
    for(int i=0;i<m;i++){
        ll ct,p;
        cin>>p>>ct;
        long long x=ct*cost[p];
        long long x_=x/2;
        ans+=x-x_;
    }
    cout<<ans<<endl;
    return 0;
}