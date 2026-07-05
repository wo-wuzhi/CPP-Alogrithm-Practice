#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin>>n;
    vector<ll>a;
    vector<ll>b;
    vector<ll>c;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x%6==0)cout<<x<<' ';
        else if(x%2==0)a.push_back(x);
        else if(x%3==0)c.push_back(x);
        else b.push_back(x);
    }
    int i=0;
    while(i<a.size()){
        cout<<a[i]<<' ';
        i++;
    }
    i=0;
    while(i<b.size()){
        cout<<b[i]<<' ';
        i++;
    }
    i=0;
    while(i<c.size()){
        cout<<c[i]<<' ';
        i++;
    }
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