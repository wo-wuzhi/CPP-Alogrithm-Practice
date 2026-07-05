#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,cnt=0,ans=0;
    cin>>n;
    vector<int>a(2*n,0);
    map<int,int>b;
    for(int i=0;i<2*n;i++) {
        cin>>a[i];
        b[a[i]]++;
        if(b[a[i]]==1) cnt++;
    }
    if(cnt==2*n){cout<<2*n<<endl;return;}
    int cnt0=0,cnt1=0,bu=0;
    for(auto it=b.begin();it!=b.end();it++){
        if(it->second%2==0){ cnt0++;}
        else cnt1++;
    }
    if(cnt1>0){cout<<cnt1+2*cnt0<<endl;return;}
    else{
        if(cnt0%2==n%2) cout<<2*cnt0<<endl;
        else cout<<2*(cnt0-1)<<endl;
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