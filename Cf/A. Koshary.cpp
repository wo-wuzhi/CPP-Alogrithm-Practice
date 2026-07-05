#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int x,y;
    cin>>x>>y;
    if(x%2==1&&y%2==1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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