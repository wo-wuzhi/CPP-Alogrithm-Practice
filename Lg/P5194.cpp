#include<bits/stdc++.h>
using namespace std;
typedef long long ll;      //dfs(剪枝)，**利用前缀和剪枝（当前值小于当前最优）

void dfs(vector<int>&a,vector<ll>&b,int t,ll* ans,ll cur,int m){
    if(cur>m) return;
    if(cur>*ans) *ans=cur;
    for(int i=t;i>=0;i--){
        if(cur+b[i+1]<*ans) return;  //** 
        if(cur+a[i]==m){*ans=m;return;}
        if(cur+a[i]<m){
            dfs(a,b,i-1,ans,cur+a[i],m);
        }
    }
}

int main(){
    int n,m,t=-1;
    ll ans=0,cur=0;
    cin>>n>>m;
    vector<int>a(n);
    vector<ll>b(n+1);
    b[0]=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i+1]=b[i]+a[i];
        if(a[i]<=m) t=i;
    }
    if(a[t]==m){cout<<m<<endl;return 0;}
    if(t==-1){cout<<0<<endl;return 0;}
    if(b[n]<=m){cout<<b[n]<<endl;return 0;}
    dfs(a,b,t,&ans,cur,m);
    cout<<ans<<endl;
    return 0;
}