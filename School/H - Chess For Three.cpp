#include<bits/stdc++.h>
using namespace std;

void solve(){
    int sum=0;
    vector<int>a(3,0);
    for(int i=0;i<3;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%2==0){
        if(a[2]<a[0]+a[1]){cout<<(a[0]+a[1]+a[2])/2<<endl;}
        else cout<<a[0]+a[1]<<endl;
    }else{
        cout<<-1<<endl;
    }
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