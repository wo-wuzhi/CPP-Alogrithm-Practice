#include<bits/stdc++.h>
using namespace std;       buti  cf  d2

int t;

void solve(){
    int n,cnt1=0,cnt0=0;
    vector<int>a1,a0;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1') {cnt1++;a1.push_back(i+1);}
        else {cnt0++;a0.push_back(i+1);}
    }
    if(cnt0==0) {cout<<-1<<endl;return;}
    if(cnt0==1) {cout<<1<<endl<<a0[0]<<endl;return;}
    if(cnt0==n) {cout<<0<<endl;return;}
    if(cnt0%2==0&&cnt1%2==1){
        cout<<-1<<endl;
    }else{
        if(cnt0%2==1){
            cout<<cnt0<<endl;
            for(auto it:a0) cout<<it<<' ';
        }else if(cnt1%2==0){
            cout<<cnt1<<endl;
            for(auto it:a1) cout<<it<<' ';
        }else cout<<-1<<endl;
    }
}

int main(){
    cin>>t;
    while(t>0){
        t--;
        solve();
    }
    return 0;
}