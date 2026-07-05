#include<iostream>
#include<vector>        //二分枚举求线性数据最小间隔的最大值
#include<algorithm>
using namespace std;

int check(int x,vector<int>&a,int n){
    int stand=0,cnt=0;
    for(int i=0;i<n+1;i++){
        if(a[i]-stand<x) cnt++;
        else stand=a[i];
    }
    return cnt;
}

int main(){
    int len,n,m;
    cin>>len>>n>>m;
    vector<int>a(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    a[n]=len;
    int l=0,r=len,ans,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid,a,n)<=m){
            l=mid+1;
            ans=mid;
        }else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}