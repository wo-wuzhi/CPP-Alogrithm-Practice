#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void solve(){
    int m,n,x,y;
    cin>>m>>n;
    vector<vector<char>>a(m,vector<char>(n));
    vector<vector<bool>>b(m,vector<bool>(n,true));
    vector<vector<int>>p(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(a[i][j]=='L'){x=i,y=j;}
            else if(a[i][j]=='#')b[i][j]=false;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<4;k++){
                int nx=i+d[k][0];
                int ny=j+d[k][1];
                if(nx<0||nx>=m||ny<0||ny>=n)continue;
                if(a[nx][ny]=='#')continue;
                p[i][j]++;
            }
        }
    }
    queue<pair<int,int>>q;
    q.push({x,y});
    b[x][y]=false;
    while(!q.empty()){
        auto [cx,cy]=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=cx+d[i][0];
            int ny=cy+d[i][1];
            if(nx<0||nx>=m||ny<0||ny>=n)continue;
            if(a[nx][ny]=='#'||!b[nx][ny])continue;
            p[nx][ny]--;
            if(p[nx][ny]<=1){b[nx][ny]=false;a[nx][ny]='+';q.push({nx,ny});}
        }
        
    }
    a[x][y]='L';
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j];
        }
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