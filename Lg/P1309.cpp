#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct people{     //赢的人有序，输的人也有序，故归并排序只需n/2，优于n*log n/快排
    int rank;
    int ori;
    int pow;
};

bool cmp(people p1,people p2){
    if(p1.ori!=p2.ori) return p1.ori>p2.ori;
    return p1.rank<p2.rank;
}

int main(){
    int n,r,q;
    cin>>n>>r>>q;
    people p[2*n],win[n],lose[n];
    for(int i=0;i<2*n;i++){
        p[i].rank=i+1;
        cin>>p[i].ori;
    }
    for(int i=0;i<2*n;i++){
        cin>>p[i].pow;
    }
    sort(p,p+2*n,cmp);
    for(int i=0;i<r;i++){
        for(int j=0;j<2*n;j+=2){
            if(p[j].pow>p[j+1].pow){
                p[j].ori++;
                win[j/2]=p[j];
                lose[j/2]=p[j+1];
            }else 
            {
                p[j+1].ori++;
                win[j/2]=p[j+1];
                lose[j/2]=p[j];
            }
        }
        int wm=0,ln=0,j=0;
        while(wm<n&&ln<n){
            if(cmp(win[wm],lose[ln])){
                p[j]=win[wm];
                wm++;
                j++;
            }else{
                p[j]=lose[ln];
                ln++;
                j++;
            }
        }
        while(wm<n) p[j++]=win[wm++];
        while(ln<n) p[j++]=lose[ln++];
    }
    cout<<p[q-1].rank;
    return 0;
}
