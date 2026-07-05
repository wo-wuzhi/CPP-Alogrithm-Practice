#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,cnta=0,cntb=0,cta=0,ctb=0,p;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    for(int i=0;i<n;i++){cin>>a[i];if(a[i]==1)cnta++;}
    for(int i=0;i<n;i++){cin>>b[i];if(b[i]==1)cntb++;}
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            if((i+1)%2==1) cta++;
            else ctb++;
            p=i+1;
        }
    }
    if(cnta%2==cntb%2){
        cout<<"Tie"<<endl;
        return;
    }else {
        if(p%2==1)cout<<"Ajisai"<<endl;
        else cout<<"Mai"<<endl;
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