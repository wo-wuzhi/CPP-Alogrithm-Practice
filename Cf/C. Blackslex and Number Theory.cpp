#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,ans;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    ans=a[0];
    if(a[1]>2*a[0]) ans=a[1]-a[0];
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