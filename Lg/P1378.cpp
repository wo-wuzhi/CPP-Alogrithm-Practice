#include<bits/stdc++.h>
using namespace std;
typedef long double ld;       //sp   dfs
                             //注意浮点数超 精度/范围 会以科学计数法输出
struct point{               //  round（）四舍五入，ceil（）向上取整，cout<<fixd<<()强制十进制输出
    int x;
    int y;
    long double r=0;
};

int n;ld ans;
point p0,p1;

ld dis(point a,point b){
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

ld firstr(point a){
    return (ld)min({abs(a.x-p0.x),abs(a.x-p1.x),abs(a.y-p0.y),abs(a.y-p1.y)});
}

void dfs(vector<point>&a,vector<bool>&b,ld cur){
    if(cur<ans) ans=cur;
    for(int i=0;i<n;i++){
        if(b[i]){
            for(int j=0;j<n;j++){
                if(b[j]==false){
                    if(dis(a[i],a[j])<=a[j].r) a[i].r=0;
                    else a[i].r=min(dis(a[i],a[j])-a[j].r,a[i].r);
                }
            }
            b[i]=false;
            dfs(a,b,cur-3.141592653*pow(a[i].r,2));
            b[i]=true;
            a[i].r=firstr(a[i]);
        }
    }
    return;
}

int main(){
    cin>>n>>p0.x>>p0.y>>p1.x>>p1.y;
    ans=(ld)abs((p0.x-p1.x)*(p0.y-p1.y));
    vector<point>a(n);
    vector<bool>b(n,true);
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].r=firstr(a[i]);
    }
    dfs(a,b,abs((p0.x-p1.x)*(p0.y-p1.y)));
    int res=round(ans);
    cout<<fixed<<res<<endl;
    return 0;
}