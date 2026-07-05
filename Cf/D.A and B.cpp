#include<iostream>
#include<vector>
using namespace std;

long long cnt(vector<int>&x,int k){
    long long n=x.size(),res=0;
    if(n==0||n==k) return 0;
    for(int i=0;i<n;i++) x[i]-=i;
    int mid=x[n/2];
    if(mid<0)mid=0;
    else if(mid+n>k) mid=k-n;
    for(int i=0;i<n;i++) res+=abs(x[i]-mid);
    return res;
}

void solve(){
    int n;
    cin>>n;
    vector<int>a;
    vector<int>b;
    for(int i=0;i<n;i++){
        char tp;
        cin>>tp;
        if(tp=='a')a.push_back(i);
        else b.push_back(i);
    }
    long long ans=min(cnt(a,n),cnt(b,n));
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