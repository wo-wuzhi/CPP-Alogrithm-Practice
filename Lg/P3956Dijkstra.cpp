#include<bits/stdc++.h>
using namespace std;           //Dijkstra 算法+优先队列

int m,n,used=0;           //该算法用于解决非负权值的最短路问题（p1126同）
int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

struct mem{
    int x,y,color=-1,mg=0,cost=INT_MAX;
    mem() : x(0), y(0), color(-1), mg(0), cost(INT_MAX) {}    //默认构造函数
    mem(int a,int b,int c,int d,int e):x(a),y(b),color(c),mg(d),cost(e){}  //构造函数
    bool operator>(const mem& other) const{
        return cost>other.cost;                 //重载>使得mem类型数据能直接比较
    }
};

int main(){
    cin>>m>>n;
    vector<vector<int>>a(m,vector<int>(m,-1));
    vector<vector<vector<int>>>c(m,vector<vector<int>>(m,vector<int>(2,INT_MAX)));
    //根据是否使用魔法开一个三维数组储存最优cost
    /*   使用二维：1  0
                 -1  -1
        该情况可能会将左下-1的cost取为到右下的最优，而实际上坐下无法到右下
    */
    priority_queue<mem,vector<mem>,greater<mem>>pq;
    c[0][0][0]=0;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        cin>>a[x-1][y-1];
    }
    pq.push(mem(0,0,a[0][0],0,0));
    while(!pq.empty()){
        auto [x,y,color,mg,cost]=pq.top();
        pq.pop();
        for(int i=0;i<4;i++){
            int nx=x+d[i][0];
            int ny=y+d[i][1];
            if(nx<0||nx>=m||ny<0||ny>=m) continue;
            if(cost>c[x][y][mg]) continue;         //提前判断，减少重复计算
            if(a[nx][ny]!=-1){
                int nc=cost+(color!=a[nx][ny]?1:0);
                int nmg=0;
                if(nc<c[nx][ny][nmg]){
                    c[nx][ny][nmg]=nc;
                    pq.push(mem(nx,ny,a[nx][ny],nmg,nc));
                }
            }else{
                if(mg==0){
                    int nc=cost+2;
                    int nmg=1;
                    if(nc<c[nx][ny][nmg]){
                        c[nx][ny][nmg]=nc;
                        pq.push(mem(nx,ny,a[x][y],nmg,nc));
                    }
                }
            }
        }
    }
    int ans=min({c[m-1][m-1][0],c[m-1][m-1][1]});
    if(ans==INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}