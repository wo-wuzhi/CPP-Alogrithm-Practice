#include<bits/stdc++.h>
using namespace std;          //bfs   用于求等权最短步数

int d[8][2]={{1,2},{1,-2},{-1,-2},{-1,2},{2,1},{2,-1},{-2,1},{-2,-1}};

void bfs(vector<vector<bool>>&a,vector<vector<int>>&b,queue<pair<int,int>>&qu,int n,int m,int cur,int nx,int ny){
    if(qu.empty()) return;
    auto [x,y]=qu.front();
    qu.pop();

    if(b[x][y]!=b[nx][ny]) cur++;
    
    for(int i=0;i<8;i++){
        int ix=d[i][0]+x;
        int iy=d[i][1]+y;
        if(ix>=0&&ix<n&&iy>=0&&iy<m&&a[ix][iy]){
            
            b[ix][iy]=cur;
            qu.push({ix,iy});
            a[ix][iy]=false;
        }
    }
    bfs(a,b,qu,n,m,cur,x,y);
}

int main(){
    int n,m,x,y,cur=1;
    cin>>n>>m>>x>>y;
    vector<vector<bool>>a(n,vector<bool>(m,true));
    vector<vector<int>>b(n,vector<int>(m,-1));
    queue<pair<int,int>>qu;
    qu.push({x-1,y-1});
    a[x-1][y-1]=false;
    b[x-1][y-1]=0;
    bfs(a,b,qu,n,m,cur,x-1,y-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<b[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}