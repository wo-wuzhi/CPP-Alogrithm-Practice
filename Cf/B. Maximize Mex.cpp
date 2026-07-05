#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll>c(n);
    map<ll,ll>a;
    map<ll,ll>b;
    for(int i=0;i<n;i++){
        cin>>c[i];
        a[c[i]]++;
    }
    if(a[0]==0){cout<<0<<endl;return;}
    sort(c.begin(),c.end());
    int j=0;
    for(int i=0;i<n;i++){
        while(j<n&&c[j]<i){b[c[j]%k]++;j++;}
        if(a[i]>0){b[i%k]--;continue;}
        else{
            if(b[i%k]==0){cout<<i<<endl;return;}
            else b[i%k]--;
        }
    }
    cout<<n<<endl;
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