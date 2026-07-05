#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n);
    vector<ll>b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int j=0;j<m;j++)cin>>b[j];
    if(b.size()==1){
        for(int i=0;i<n;i++){
            if(i==0) a[0]=min(a[0],b[0]-a[0]);
            else{
                if(a[i]>=a[i-1]){
                    if(b[0]-a[i]>=a[i-1])a[i]=min(a[i],b[0]-a[i]);
                }else{
                    if(b[0]-a[i]>=a[i-1])a[i]=b[0]-a[i];
                    else{cout<<"NO"<<endl;return;}
                }
            }
        }
        cout<<"YES"<<endl;
    }else{
        sort(b.begin(),b.end());
        a[0]=min({a[0],b[m-1]-a[0],b[0]-a[0]});
        for(int i=1;i<n;i++){
            auto it=lower_bound(b.begin(),b.end(),a[i]+a[i-1]);
            if(it==b.end()&&a[i]<a[i-1]){cout<<"NO"<<endl;return;}
            a[i]=min(a[i],b[it-b.begin()]-a[i]);
        }
        cout<<"YES"<<endl;
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