#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double dis(ll a,ll b,ll c,ll d){
    return (double)sqrt(pow(a-c,2)+pow(b-d,2));
}

void solve(){
    ll n,px,py,qx,qy,sum=0,ma=0;
    cin>>n>>px>>py>>qx>>qy;
    vector<ll>a(n);
    double d=dis(px,py,qx,qy);
    for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];ma=max(ma,a[i]);}
    if(n==1){
        if(d==(double)a[0])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }
    if(double(ma)<d){
        if(double(sum)<d){cout<<"NO"<<endl;return;}
    }else{
        sum-=ma;
        double s=(double)sum+d;
        if(s<(double)ma){cout<<"NO"<<endl;return;}
    }
    cout<<"YES"<<endl;
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