#include<bits/stdc++.h>
using namespace std;

int arr[200003]={0};

void aaa(){
    for(int i=1;i<=200000;i++){
        int x=i;
        while(!(x&1)){x>>=1;}
        arr[i]=x;
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int>a(n+1,0);
    for(int i=1;i<=n;i++){cin>>a[i];}
    for(int i=1;i<=n;i++){
        if(arr[a[i]]!=arr[i]){
            cout<<"NO"<<endl; return;
        }
    }
    cout<<"YES"<<endl;
}

int main(){
    int t;
    cin>>t;
    aaa();
    while(t>0){
        t--;
        solve();
    }
}