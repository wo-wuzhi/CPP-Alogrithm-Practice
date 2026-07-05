#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,cnt=0;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){cin>>a[i];}
    for(int i=0;i<n-1;i++){
        if(a[i]+a[i+1]==7||a[i]==a[i+1]){
            cnt++;
            if(i<n-2)
            if(a[i+1]+a[i+2]==7||a[i+1]==a[i+2]) i++;
        }
    }
    cout<<cnt<<endl;
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