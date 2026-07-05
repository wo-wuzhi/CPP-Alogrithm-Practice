#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s;
    cin>>s;
    int n=s.length();
    if(n==1){cout<<1<<endl;return;}
    for(int i=0;i<n;i++){
        if(s[i]=='*'&&i>0&&(s[i-1]=='*'||s[i-1]=='>')){cout<<-1<<endl;return;}
        if(s[i]=='*'&&i<n-1&&s[i+1]=='<'){cout<<-1<<endl;return;}
        if(s[i]=='>'&&i<n-1&&s[i+1]=='<'){cout<<-1<<endl;return;}
    }
    int i=0,ans=-1,tp=0;
    while(s[i]=='<'&&i<n){
        tp++;
        i++;
    }
    if(s[i]=='*')tp++;
    ans=max(ans,tp);
    i=n-1,tp=0;
    while(i>=0&&s[i]=='>'){
        tp++;
        i--;
    }
    if(s[i]=='*')tp++;
    ans=max(ans,tp);
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