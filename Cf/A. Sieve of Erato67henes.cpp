#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,ch1=-1,ch2=-1;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==67){ch1=1;}
    }
    if(ch1==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        solve();
    }
}