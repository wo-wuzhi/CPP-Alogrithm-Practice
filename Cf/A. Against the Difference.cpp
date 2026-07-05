#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int num=2e5+10;
deque<int>dq[num];

void solve(){
    int n;
    cin>>n;
    vector<int>dp(n+1,0);
    vector<int>a(n+1);
    for(int i=1;i<=n;i++) {cin>>a[i];}
    for(int i=1;i<=n;i++){ 
        dp[i]=dp[i-1];
        dq[a[i]].push_back(i);
        if(dq[a[i]].size()>a[i]) dq[a[i]].pop_front();
        if(dq[a[i]].size()==a[i]){
            dp[i]=max(dp[i],dp[dq[a[i]].front()-1]+a[i]);
        }
    }
    cout<<dp[n]<<endl;
    for(int i=1;i<=n;i++) if(!dq[a[i]].empty())dq[a[i]].clear();
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