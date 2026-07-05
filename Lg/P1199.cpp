#include<bits/stdc++.h>
using namespace std;           //贪心+sp博弈（一定会赢）

int main(){
    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(n,0));
    for(int i=0;i<n-1;i++){
        int j=i+1;
        while(j<=n-1){
            cin>>a[i][j];
            a[j][i]=a[i][j];
            j++;
        }
    }
    int secmax=0;
    vector<int>tem(n);
    for(int i=0;i<n;i++){
        tem=a[i];
        sort(tem.begin(),tem.end());
        secmax=max({secmax,tem[n-2]});
    }
    cout<<1<<endl<<secmax;
    return 0;
}