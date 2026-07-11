#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll l,r,cnt=0;
    cin>>l>>r;
    cnt=r-r/2-r/3-r/5-r/7+r/(2*3)+r/(2*5)+r/(2*7)+r/(3*5)+r/(3*7)+r/(5*7)-r/(2*3*5)-r/(2*3*7)-r/(2*5*7)-r/(3*5*7)+r/(2*3*5*7)-1;
    ll tp=l-l/2-l/3-l/5-l/7+l/(2*3)+l/(2*5)+l/(2*7)+l/(3*5)+l/(3*7)+l/(5*7)-l/(2*3*5)-l/(2*3*7)-l/(2*5*7)-l/(3*5*7)+l/(2*3*5*7)-1;
    cnt-=tp;
    if(l%2!=0&&l%3!=0&&l%5!=0&&l%7!=0)cnt++;
    cout<<cnt<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        solve();
    }
}