#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){cin>>a[i];}
    sort(a.begin(),a.end());
    int ma=0;
    for(int i=0;i<n;i+=2){
        if(max(ma,a[i])!=max(ma,a[i+1])){
            cout<<"NO"<<endl;
            return;
        }
        ma=max(ma,a[i])+1;
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
}