#include<bits/stdc++.h>
using namespace std;

int m,n;
char a[1005][1005];
bool b[1005][1005];
int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int bfs(int i,int j){
    b[i][j]=false;
    bool ch=true;
    if(i==0 || i==m-1 || j==0 || j==n-1) ch=false;
    queue<pair<int,int>>qu;
    qu.push({i,j});
    while(!qu.empty()){
        auto [nx,ny]=qu.front();
        qu.pop();
        for(int k=0;k<4;k++){
            int x=nx+d[k][0];
            int y=ny+d[k][1];
            if(x>=0&&x<m&&y>=0&&y<n&&b[x][y]){
                b[x][y]=false;
                qu.push({x,y});
                if(x==0||x==m-1||y==0||y==n-1) ch=false;
            }
        
        }
    }
    if(ch)  return 1;
    else return 0;
}

int main(){
    int cnt=0;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(a[i][j]=='.')
            b[i][j]=true;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]=='.'&&b[i][j]) cnt+=bfs(i,j);
        }
    }
    cout<<cnt;
    return 0;
}