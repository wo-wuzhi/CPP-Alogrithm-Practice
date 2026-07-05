#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
   int n,k,len,cnt0=0;
   cin>>n>>k;
   string s;
   cin>>s;
   len=s.length();
   for(int i=0;i<len;i++){
        if(s[i]=='0')cnt0++;
   }
   if(k>=len-cnt0||n<2*k){cout<<"Alice"<<endl;return;}
   cout<<"Bob"<<endl;
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