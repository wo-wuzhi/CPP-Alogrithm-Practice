#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n-1;i++){
        int tp=a[i];
        vector<int>p(a.begin()+i+1,a.end());
        sort(p.begin(),p.end());
        int m=upper_bound(p.begin(),p.end(),tp)-p.begin();
        int le=lower_bound(p.begin(),p.end(),tp)-p.begin();
        int len=p.size();
        int res=max(len-m,le);
        cout<<res<<' ';
    }
    
    cout<<0<<endl;
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