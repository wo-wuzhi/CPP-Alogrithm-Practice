#include<iostream>
#include<algorithm>
using namespace std;        //构建结构体；比较函数cmp从而依据两种属性对对象快排

struct p{
    int num;
    int score;
};

bool cmp(p a,p b){
    if(a.score!=b.score) return a.score>b.score;
    return a.num<b.num;
}

int main(){
    int m,n;
    cin>>n>>m;
    p a[n];
    for(int i=0;i<n;i++){
        cin>>a[i].num>>a[i].score;
    }
    sort(a,a+n,cmp);
    int t=m*3/2;
    while(true){
        if(t<n&&a[t].score==a[t-1].score){
            t++;
        }else break;
        
    }
    cout<<a[t-1].score<<' '<<t<<endl;
    for(int i=0;i<t;i++){
        cout<<a[i].num<<' '<<a[i].score<<endl;
    }
    return 0;
}