#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string a,b;
    cin>>a>>b;
    int len=a.length();
    int i=0;
    while(a[i]==b[i]) i++;
    if(i==len-1){cout<<a<<endl<<b<<endl;return;}
    string ma,mi;
    if(a[i]-'0'>b[i]-'0'){
        ma=a,mi=b;
    }else{ma=b,mi=a;}
    for(int j=i+1;j<len;j++){
        if(ma[j]-'0'>mi[j]-'0'){
            char tp=mi[j];
            mi[j]=ma[j];
            ma[j]=tp;
        }
    }
    cout<<ma<<endl<<mi<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        solve();
    }
}