#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        cin>>b[i];
        b[i]-=a[i];
    }
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=b[i];
        if(sum<0){cout<<"NO"<<endl;return;}
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