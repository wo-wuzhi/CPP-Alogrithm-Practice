#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



void solve(){
    int n;
    ll ans=0;
    cin>>n;
    vector<int>a(n,0),b(n,0),c(n,0);
    vector<bitset<5000>>l(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) cin>>c[i];
    vector<int>bb=b;bb.insert(bb.end(),b.begin(),b.end());
    vector<int>cc=c;cc.insert(cc.end(),c.begin(),c.end());
    ll ab=0,bc=0;
    for(int i=0;i<n;i++){
        bool ch=true;
        for(int j=0;j<n;j++){
            if(b[j]>=cc[i+j]){
                ch=false;
                break;
            }
        }
        if(ch) ++bc;
    }
    for(int i=0;i<n;i++){
        bool ch=true;
        for(int j=0;j<n;j++){
            if(a[j]>=bb[i+j]){
                ch=false;
                break;
            }
        }
        if(ch) ++ab;
    }
    ans=n*ab*bc;
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t>0){
        t--;
        solve();
    }
    return 0;
}