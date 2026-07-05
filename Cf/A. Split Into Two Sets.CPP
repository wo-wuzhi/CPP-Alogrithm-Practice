#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    map<int,int>a;
    vector<pair<int,int>>b(n);
    for(int i=0;i<n;i++){
        cin>>b[i].first>>b[i].second;
        a[b[i].first]++;
        a[b[i].second]++; 
    }
    for(int i=0;i<n;i++){
        if(a[b[i].first]!=2||a[b[i].second]!=2){cout<<"NO"<<endl;return;}
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