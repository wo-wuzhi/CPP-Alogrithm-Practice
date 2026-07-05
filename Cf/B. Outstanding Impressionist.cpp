#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>>a(n);
    vector<int>cnt(2*n+2,0);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
        if(a[i].first==a[i].second){cnt[a[i].first]++;}
    }
    vector<int>b(2*n+2,0);
    for(int i=1;i<2*n+2;i++){
        b[i]=b[i-1]+((cnt[i]>0)?1:0);
    }
    for(int i=0;i<n;i++){
        if(a[i].first==a[i].second){
            if(cnt[a[i].first]>=2)cout<<0;
            else cout<<1;
        }else{
            if(b[a[i].second]-b[a[i].first-1]!=a[i].second-a[i].first+1)cout<<1;
            else cout<<0;
        }
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
    return 0;
}