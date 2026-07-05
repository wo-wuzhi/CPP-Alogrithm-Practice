#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
   int n,m,ans=0;
   cin>>n>>m;
   map<int,int>a;
   map<int,int>b;
   for(int i=0;i<n;i++){
        int x; cin>>x;
        a[x]++;
   }
   for(int i=0;i<m;i++){
        int x;cin>>x;
        b[x]++;
   }
   auto l=a.begin(),r=--b.end();
   while((*l).first!=(*r).first){
        if((*l).second>(*r).second){
            (*l).second-=(*r).second;
            ans+=(*r).second;
            (*r).second=0;
            if(r!=b.begin())r--;
            else break;
        }else if((*l).second<(*r).second){
            (*r).second-=(*l).second;
            ans+=(*l).second;
            (*l).second=0;
            if((l)!=a.end())l++;
            else break;
        }else{
            ans+=(*l).second;
            (*l).second=0; (*r).second=0;
            l++; r--;
        }
   }
   auto tpl=l,tpr=r;
   if(l==a.end()){
        while(r!=b.begin()||(*r).second!=0){
            ans+=(*r).second;
            (*r).second=0;
            if(r!=b.begin())r--;
        }
   }else if(r==b.begin()){
        while(l!=a.end()){
            ans+=(*l).second;
            l++;
        }
   }else ans++;
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