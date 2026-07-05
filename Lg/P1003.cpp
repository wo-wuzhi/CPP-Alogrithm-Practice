#include<iostream>
#include<vector>
using namespace std;        //sp

struct point{
    int x;
    int y;
};
struct tanzi{
    point p;
    int lenx;
    int leny;
};

int main(){
    int t;
    cin>>t;
    tanzi tan[t];
    point needp;
    for(int i=0;i<t;i++){
        cin>>tan[i].p.x>>tan[i].p.y>>tan[i].lenx>>tan[i].leny;
    }
    cin>>needp.x>>needp.y;
    int ans=-1;
    for(int i=0;i<t;i++){
        if(needp.x<=tan[i].p.x+tan[i].lenx&&needp.x>=tan[i].p.x&&needp.y>=tan[i].p.y&&needp.y<=tan[i].p.y+tan[i].leny){
            ans=i+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}