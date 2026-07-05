#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>>t(2,vector<int>(m+1,0));
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    t[0][a]++;
    t[1][b]++;
  }
  for(int i=1;i<=m;i++){
    cout<<t[1][i]-t[0][i]<<endl;
  }
  return 0;
}