#include<bits/stdc++.h>
using namespace std;               //二维前缀和

bool he(vector<vector<int>>&b,int l){
    int ans=0;
    for(int i=l;i<=b.size()-1;i++){
        for(int j=l;j<=b[0].size()-1;j++){
            ans=b[i][j]-b[i-l][j]-b[i][j-l]+b[i-l][j-l];
            if(ans==l*l) return true;
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    int l=min({m,n});
    vector<vector<int>>a(n,vector<int>(m));
    vector<vector<int>>b(n+1,vector<int>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[i][j]=a[i-1][j-1]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
        }
    }
    while(l>=1&&!he(b,l)) l--;
    cout<<l;
    return 0;
}