#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vec;        //记忆化搜索（若都能覆盖，则每个起点的覆盖区间连续）

int n,m;
int d[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

void dfs(vec&a,vec&l,vec&r,vector<vector<bool>>&ch,int x,int y){
    if(!ch[x][y]) return;
    ch[x][y]=false;
    for(int i=0;i<4;i++){
        int nx=x+d[i][0];
        int ny=y+d[i][1];
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&a[nx][ny]<a[x][y]){
            if(ch[nx][ny])
            dfs(a,l,r,ch,nx,ny);
            l[x][y]=min(l[x][y],l[nx][ny]);   //水覆盖只需满足从高到低，是否走过没有限制，不再dfs时说明此起点与左侧起点覆盖范围已连接
            r[x][y]=max(r[x][y],r[nx][ny]);  //无论是否走过该格，都继续更新区间（因为该格被其它起点覆盖过所以为false，但此起点没走过）
        }
    }

}

struct LR{
    int l,r;
    bool operator<(const LR&oth)const{
        if(l==oth.l) return r>oth.r;
        else return l<oth.l;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m));
    vector<vector<int>>l(n,vector<int>(m,INT_MAX));
    vector<vector<int>>r(n,vector<int>(m,-1));
    vector<vector<bool>>ch(n,vector<bool>(m,true));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(i==n-1){
                l[i][j]=j;
                r[i][j]=j;  //最后一行l，r赋值为对应j，便于区间的比较
            }
        }
    }
    vector<LR>lr(m);
    for(int i=0;i<m;i++){
        if(ch[0][i]){  //剪枝，若该起点被其它起点走过便跳过
            dfs(a,l,r,ch,0,i);
        }
        lr[i]={l[0][i],r[0][i]};  //记录所有起点对应区间，以便后续选择最优方案
    }
    int cnt=0;
    for(int i=0;i<m;i++){
        if(ch[n-1][i]) cnt++;
    }
    if(cnt!=0){
        cout<<0<<endl<<cnt<<endl;   //最后一行若有未覆盖的，则统计未覆盖个数并输出
        return 0;
    }
    sort(lr.begin(),lr.end());
    int ans=0,cur=0,pos=0;
    while(cur<m){
        int maxr=cur;       //贪心选择出起点最少的最优方案
        while(pos<m&&lr[pos].l<=cur){
            maxr=max(maxr,lr[pos].r);
            pos++;
        }
        ans++;
        cur=maxr+1;
    }
    cout<<1<<endl<<ans<<endl;
    return 0;
}