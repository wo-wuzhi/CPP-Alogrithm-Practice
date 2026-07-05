#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long check(int mid,vector<pair<int,int>>&qu,vector<int>&w,vector<int>&v,int n){
    long long sum=0;
    vector<long long>wcnt(n+1);
    vector<long long>vsum(n+1);
    wcnt[0]=0;
    vsum[0]=0;
    for(int i=1;i<n+1;i++){
        wcnt[i]=wcnt[i-1]+(w[i-1]>mid?1:0);
        vsum[i]=vsum[i-1]+(w[i-1]>mid?v[i-1]:0);
    }
    for(int i=0;i<qu.size();i++){
        int begin=qu[i].first;
        int end=qu[i].second;
        sum+=(wcnt[end]-wcnt[begin-1])*(vsum[end]-vsum[begin-1]);
    }
    return sum;
}

int main(){
    int n,m;
    long long s;
    cin>>n>>m>>s;
    vector<int>w(n);
    vector<int>v(n);
    
    int l=0,r=0,mid=0;
    long long cur=0,ans=1e18;
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
        l=min({l,w[i]});
        r=max({r,w[i]});
        
    }
    vector<pair<int,int>>qu(m);
    for(int i=0;i<m;i++){
        cin>>qu[i].first>>qu[i].second;
    }
    while(l<=r){
        mid=(l+r)/2;
        cur=check(mid,qu,w,v,n);
        ans=min({ans,abs(s-cur)});
        if(cur==0) break;
        if(s>cur){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}