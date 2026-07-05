#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,sum=0,cnt=0;
    cin>>n;
    vector<int>a(n,0);
    map<int,int>b;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(b[a[i]]==0)sum+=a[i];
        b[a[i]]++;
    }
    if(sum>n){ cout<<-1<<endl;return;}
    for(auto it=b.begin();it!=b.end();it++){
        if(it->second%it->first!=0){cout<<-1<<endl;return;}
        cnt+=it->second/it->first;
    }
    vector<int>ans(n);
    map<int,int>curc;
    map<int,int>ct;
    int p=1;
    for(int i=0;i<n;i++){
        if(curc.find(a[i])==curc.end()||ct[a[i]]==a[i]){
            curc[a[i]]=p++;
            ct[a[i]]=0;
        }
        cout<<curc[a[i]]<<' ';
        ct[a[i]]++;
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