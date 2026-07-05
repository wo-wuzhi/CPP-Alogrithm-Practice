#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int h,w,bx,by,ex,ey;
vector<vector<char>>a;
vector<vector<bool>>b;
int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
string c="RLUD",res;

void dfs(int x,int y,int cnt,int p){
    if(x==ex&&y==ey){
        cout<<"Yes"<<res<<endl;
    }
    if(a[x][y]=='o'){
        auto [px,py]=d[p];
        res+=c[p];
        dfs(x+px,y+py,cnt++,p);
    }
    for(int i=0;i<4;i++){

    }
}

int main(){
    cin>>h>>w;
    a.resize(h,vector<char>(w));
    b.resize(h,vector<bool>(w,true));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
            if(a[i][j]=='S'){bx=i;by=j;}
            else if(a[i][j]=='G'){ex=i;ey=j;}
            else if(a[i][j]=='#'){b[i][j]=false;}
        }
    }
    return 0;
}