#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,d;
    cin>>n>>d;
    bool a[11]={false};
    for(int i=0;i<=4;i++){
        if(d%(2*i+1)==0)a[2*i+1]=true;
    }
    int i=0;
    if(n>=3) {a[7]=true;a[3]=true;}
    if(n>=3&&a[3]||n>=6) a[9]=true;
    for(int i=0;i<=4;i++){ 
        if(a[2*i+1])cout<<2*i+1<<' ';
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