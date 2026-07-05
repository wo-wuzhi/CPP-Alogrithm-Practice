#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,k;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    k=a[1]-a[0];
    if(a.size()>2){
        for(int i=1;i<n-1;i++){
            if(a[i+1]-a[i]!=k){cout<<"NO"<<endl;return;}
        }
    }
    if((2*a[0]-a[1])>=0&&(2*a[0]-a[1])%(n+1)==0&&(a[0]-n*(2*a[0]-a[1])/(n+1)>=0))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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