#include<bits/stdc++.h>
using namespace std;

struct v{
    int l,w,h;
};

void solve(){
    int n,m;
    cin>>n>>m;
    vector<v>a(m);
    vector<int>ma(m);
    vector<int>mi(m);
    vector<int>fib(n+1);
    fib[1]=1,fib[2]=2;
    for(int i=0;i<m;i++){
        cin>>a[i].w>>a[i].l>>a[i].h;
        ma[i]=max({a[i].w,a[i].l,a[i].h});
        mi[i]=min({a[i].w,a[i].l,a[i].h});
    }
    for(int i=3;i<=n;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    for(int i=0;i<m;i++){
        if(fib[n]+fib[n-1]<=ma[i]&&fib[n]<=mi[i]) cout<<"1";
        else cout<<"0";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        solve();
    }
}