#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,ctl=0,ctr=0;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='(') ctl++;
        else ctr++;
    }
    if(n%2==1||ctl!=ctr)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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