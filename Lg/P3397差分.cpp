#include<bits/stdc++.h>
using namespace std;               //二维差分

void diff(int x1,int y1,int x2,int y2,vector<vector<int>>&dif){
    dif[x1][y1]+=1;
    dif[x1][y2+1]-=1;
    dif[x2+1][y1]-=1;
    dif[x2+1][y2+1]+=1;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>pre(n+2,vector<int>(n+2,0));
    vector<vector<int>>dif(n+2,vector<int>(n+2,0));
    while(m>0){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        diff(x1,y1,x2,y2,dif);
        m--;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pre[i][j]=pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1]+dif[i][j];
            cout<<pre[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}