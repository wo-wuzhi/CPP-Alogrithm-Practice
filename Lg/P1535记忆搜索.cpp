#include<bits/stdc++.h>
using namespace std;        //记忆化搜索(P1413,P1514)

int n,m,t,bx,by,ex,ey,res=0;
int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int memodfs( vector<vector<char>>&a,vector<vector<vector<int>>>&memo,int x,int y,int cnt){
    if(x<0||x>=n||y<0||y>=m||a[x][y]=='*') return 0;
    if(cnt==t) return (x==ex-1&&y==ey-1)?1:0;
    if(memo[cnt][x][y]!=-1) return memo[cnt][x][y];
    int res=0;
    for(int i=0;i<4;i++){
        int nx=x+d[i][0];
        int ny=y+d[i][1];
        res+=memodfs(a,memo,nx,ny,cnt+1);
    }
    memo[cnt][x][y]=res;  //不同cnt对应的路线是不同的，故用三维数组记录
    return res;
}

int main(){
    cin>>n>>m>>t;
    vector<vector<char>>a(n,vector<char>(m));
    vector<vector<vector<int>>>memo(t,vector<vector<int>>(n,vector<int>(m,-1)));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
    cin>>bx>>by>>ex>>ey;
    int ans=memodfs(a,memo,bx-1,by-1,0);
    cout<<ans;
    return 0;
}