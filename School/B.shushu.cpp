#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll sum=a+b+c+d,ma=max({a,b,c,d});
    if(sum+1<2*ma){cout<<0<<endl;return 0;}
    
    return 0;
}