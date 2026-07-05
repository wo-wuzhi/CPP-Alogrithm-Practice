#include<bits/stdc++.h>
using namespace std;         //记忆化搜索

int n,m,mi=0,mj=0,ma=0;
int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int memodfs(vector<vector<int>>&a,vector<vector<int>>&memo,int x,int y){
    if(memo[x][y]!=-1) return memo[x][y];
    int res=1;
    for(int i=0;i<4;i++){
        int nx=x+d[i][0];
        int ny=y+d[i][1];
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&a[nx][ny]<a[x][y]){
            res=max(res,memodfs(a,memo,nx,ny)+1);
        }
    }
    memo[x][y]=res;
    return res;
}

int main(){
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m));
    vector<vector<int>>memo(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans=max(ans,memodfs(a,memo,i,j));
        }
    }
    cout<<ans;
    return 0;
}