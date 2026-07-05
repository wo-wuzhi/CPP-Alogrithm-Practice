#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x;
    cin>>x;
    if(x!=67)
    cout<<x+1<<endl;
    else cout<<x<<endl;
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