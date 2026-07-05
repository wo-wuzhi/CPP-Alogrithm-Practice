#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,cnt=0;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    for(int i=0;i<n;i++){cin>>a[i];}
    for(int i=0;i<n;i++){cin>>b[i];}
    for(int i=0,j=0;i<n&&j<n;){
        if(a[i]>b[j]){
            j++;
            cnt++;
        }else{
            i++;
            j++;
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