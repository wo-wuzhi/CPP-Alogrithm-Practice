#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;

void solve(){
    int ma=0,cnt=0;
    cin>>n>>m;
    vector<vector<int>>a(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            ma=max(ma,a[i][j]);
        }
    }
    int x1,y1,x2,y2;
    bool ch=true,ch2=true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==ma){
                cnt++;
                if(ch){
                    x1=i,y1=j;
                    ch=false;
                }else if(ch2&&x1!=i&&y1!=j){
                    x2=i,y2=j;
                    ch2=false;
                }
            }
        }
    }
    if(cnt>=2&&!ch2){
        int sum=0;
        for(int i=1;i<=m;i++){
            if(a[x1][i]==ma) sum++;
        }
        for(int i=1;i<=n;i++){
            if(a[i][y2]==ma)sum++;
        }
        if(a[x1][y2]==ma)sum--;
        if(sum==cnt){cout<<ma-1<<endl;return;}
        sum=0;
        for(int i=1;i<=m;i++){
            if(a[x2][i]==ma) sum++;
        }
        for(int i=1;i<=n;i++){
            if(a[i][y1]==ma)sum++;
        }
        if(a[x2][y1]==ma)sum--;
        if(sum==cnt){cout<<ma-1<<endl;return;}
    }else{cout<<ma-1<<endl;return;}
    cout<<ma<<endl;
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