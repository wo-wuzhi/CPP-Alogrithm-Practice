#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    cout<<2*n-1<<endl;
    for(int i=1;i<n;i++){
        cout<<i<<' '<<1<<' '<<i<<endl;
        cout<<i<<' '<<i+1<<' '<<n<<endl;
    }
    cout<<n<<' '<<1<<' '<<n<<endl;
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