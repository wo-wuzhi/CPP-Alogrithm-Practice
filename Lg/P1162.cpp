#include<bits/stdc++.h>
using namespace std;          //sp  bfs

int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void bfs(queue<pair<int,int>>&qu,vector<vector<int>>&a,vector<vector<bool>>&b,int n){
    if(qu.empty()) return;
    pair<int,int> tp=qu.front();
    qu.pop();
    for(int i=0;i<4;i++){
        int ix=tp.first+d[i][0];
        int iy=tp.second+d[i][1];
        if(ix>=0&&ix<n+2&&iy>=0&&iy<n+2&&a[ix][iy]!=1&&b[ix][iy]){
            b[ix][iy]=false;
            qu.push({ix,iy});
        }
    }
    bfs(qu,a,b,n);
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>a(n+2,vector<int>(n+2,0));
    vector<vector<bool>>b(n+2,vector<bool>(n+2,true));
    queue<pair<int,int>>qu;
    qu.push({0,0});
    b[0][0]=false;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cin>>a[i][j];
        }
    }
    bfs(qu,a,b,n);
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(a[i][j]!=1&&b[i][j]) a[i][j]=2;
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}