#include<bits/stdc++.h>
using namespace std;            //Dijkstra 算法

int m,n,bx,by,ex,ey; char bf;
int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char fx[4]={'S','E','N','W'};

struct rob{
    int x=0,y=0,cnt=0,ct=0;
    char d='\0';
    rob(int x_,int y_,int cnt_,int ct_,char d_):x(x_),y(y_),cnt(cnt_),ct(ct_),d(d_){}
    bool operator>(const rob& oth) const{
        return ct>oth.ct;
    }
};

int main(){
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m,0));
    vector<vector<int>>b(n+1,vector<int>(m+1,0));
    vector<vector<vector<int>>>c(n+1,vector<vector<int>>(m+1,vector<int>(4,INT_MAX)));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]==1){
                b[i][j]=-1;b[i][j+1]=-1;b[i+1][j]=-1;b[i+1][j+1]=-1;
            }
        } 
        
    }
    cin>>bx>>by>>ex>>ey>>bf;
    int bi=0;
    while(fx[bi]!=bf){bi++;};
    c[bx][by][bi]=0;
    priority_queue<rob,vector<rob>,greater<rob>>pq;
    pq.push(rob(bx,by,0,0,bf));
    while(!pq.empty()){
        auto[x,y,cnt,ct,f]=pq.top();
        pq.pop();
        int curi=0;
        while(fx[curi]!=f){curi++;};
        if(ct>c[x][y][curi]) continue;
        for(int i=0;i<4;i++){
            int nx=x+d[i][0];
            int ny=y+d[i][1];
            char nf=fx[i];
            int nfi=i;
            if(nx<=0||nx>=n||ny<=0||ny>=m||b[nx][ny]==-1) continue;
            if(nf!=f){
                int nct;
                if(abs(nfi-curi)!=2) nct=ct+2;
                else nct=ct+3;
                if(nct<c[nx][ny][nfi]){
                    c[nx][ny][nfi]=nct;
                    pq.push(rob(nx,ny,1,nct,nf));
                }
            }else{
                int dc1=(cnt>=3?(cnt-cnt%3)/3:0)+(cnt%3!=0?1:0);
                int ncnt=cnt+1;
                int dc2=(ncnt>=3?(ncnt-ncnt%3)/3:0)+(ncnt%3!=0?1:0);
                int nct=ct-dc1+dc2;
                if(nct<c[nx][ny][nfi]){
                    c[nx][ny][nfi]=nct;
                    pq.push(rob(nx,ny,ncnt,nct,nf));
                }
            }
        }
    }
    int ans=min({c[ex][ey][0],c[ex][ey][1],c[ex][ey][2],c[ex][ey][3]});
    if(ans==INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}