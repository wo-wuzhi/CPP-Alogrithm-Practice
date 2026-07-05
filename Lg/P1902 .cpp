#include<iostream>
#include<vector>
#include<algorithm>      //二分+BFS求解二位平面经过路径的最大元素的最小值
#include<queue>
using namespace std;

int n,m;

bool check(int cost,vector<vector<int>>&a){
    int n=a.size(),m=a[0].size();
    vector<vector<bool>>ch(n,vector<bool>(m,false));
    int dirs[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
    queue<pair<int,int>>q;
    for(int j=0;j<m;j++){
        if(a[0][j]<=cost){
            q.push({0,j});
            ch[0][j]=true;
        }
    }
    while(!q.empty()){
        auto [i,j]=q.front();
        q.pop();
        if(i==n-1) return true;
        for(auto&dir:dirs){
            int ni=i+dir[0];
            int nj=j+dir[1];
            if(ni>=0&&ni<n&&nj>=0&&nj<m&&!ch[ni][nj]&&a[ni][nj]<=cost){
                ch[ni][nj]=true;
                q.push({ni,nj});
            }
        }
    }
    return false;
}

int main(){
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int l=0,r=1000,mid,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid,a)){
            r=mid-1;
            ans=mid;
        }else {
            l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}