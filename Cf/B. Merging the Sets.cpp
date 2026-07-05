#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,m,sp=0;
    cin>>n>>m;
    vector<bool>ch(n+1,true);
    vector<vector<int>>nump(m+1,vector<int>());
    for(int i=0;i<n;i++){
        int j;
        cin>>j;
        for(;j>0;j--){
            int x; cin>>x;
            nump[x].push_back(i);
        }
    }
    for(int i=1;i<=m;i++){
        if(nump[i].empty()){cout<<"NO"<<endl;return;}
        if(nump[i].size()==1&&ch[nump[i][0]]){sp++;ch[nump[i][0]]=false;}
    }
    if(n-sp>=2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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