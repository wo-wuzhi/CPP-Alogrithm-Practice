#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s;
    cin>>s;
    int sum=0;
    map<int,int>a;
    for(int i=0;i<s.length();i++){
        if(s[i]=='2'){ a[2]++;}
        if(s[i]=='3'){ a[6]++;}
        sum+=s[i]-'0';
    }
    if(sum%9==0){cout<<"YES"<<endl;return;}
    int tp=sum%9;
    for(int i=0;i<=a[2];i++){
        for(int j=0;j<=a[6];j++){
            if((2*i+6*j+tp)%9==0){cout<<"YES"<<endl;return;}
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        solve();
    }
}