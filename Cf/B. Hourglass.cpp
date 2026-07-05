#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll s,k,m;
    cin>>s>>k>>m;
    ll tp=m%k;
    
    if(tp==k){
        cout<<max((ll)0,s-m);
    }else{  
        ll cnt=(m-tp)/k,left=min(s,k);
        if(k==1){
            if(m%2==0)cout<<s;
            else cout<<1;
            cout<<endl;
            return;
        }
        if(cnt%2==0){
            if(tp==0){cout<<s;}
            else cout<<max((ll)0,s-tp);
        }else{
            cout<<max((ll)0,left-tp);
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