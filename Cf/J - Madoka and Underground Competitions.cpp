#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k,r,c;
    cin>>n>>k>>r>>c;
    char a[505][505];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){a[i][j]='.';}
    }
    a[r][c]='X';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(abs(i+j-r-c)%k==0){
                a[i][j]='X';
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){cout<<a[i][j];}
        cout<<endl;
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