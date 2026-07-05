#include<bits/stdc++.h>
using namespace std;              //sp dfs

int n,cnt=0;
vector<vector<int>>ans;
vector<bool>hang;
vector<vector<bool>>x(2,vector<bool>(2*n,true));

void dfs(int row,vector<int>&p){
    if(row==n){
        cnt++;
        if(ans.size()<3) ans.push_back(p);
        return;
    }
    for(int col=0;col<n;col++){
        if(hang[col+1]&&x[0][row-col+n]&&x[1][row+col]){
            hang[col+1]=false;
            x[0][row-col+n]=false;
            x[1][row+col]=false;
            p.push_back(col+1);
            dfs(row+1,p);
            p.pop_back();
            hang[col+1]=true;
            x[0][row-col+n]=true;
            x[1][row+col]=true;
        }
    }
}

int main(){
    cin>>n;
    hang.resize(n + 1, true);
    x[0].resize(2 * n, true);    
    x[1].resize(2 * n, true);
    vector<int>p;
    dfs(0,p);
    for(int i=0;i<3;i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<cnt<<endl;
    return 0;
}