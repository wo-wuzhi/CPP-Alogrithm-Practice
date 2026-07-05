#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,cnt=0;
    cin>>n;
    vector<char>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]=='U') cnt++;
    }
    if(cnt%2==1)
    cout<<"YES"<<endl;
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