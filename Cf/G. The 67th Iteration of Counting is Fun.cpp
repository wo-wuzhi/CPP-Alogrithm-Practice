#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct person{
    int time;
    int place;
    bool ifsit=false;
};

bool cmpt(person a,person b){
    return a.time<b.time;
}

void solve(){
    int n,m,cnt=1;
    cin>>n>>m;
    vector<person>a(n);
    vector<person>b(n);
    for(int i=0;i<n;i++){
        cin>>a[i].time;
        a[i].place=i;
    }
    b=a;
    sort(b.begin(),b.end(),cmpt);
    for(int i=0;i<n;i++){
        if(b[i].time==0) cnt++;
        else if(cnt<b[i].time||(b[i].place>0?(!a[b[i].place-1].ifsit):(!a[b[i].place+1].ifsit)&&b[i].place<n-1?(!a[b[i].place+1].ifsit):(!a[b[i].place-1].ifsit))){cout<<0<<endl;return;}
        else{
            if(b[i].place>0&&b[i].place<n-1){
                if(a[b[i].place-1].ifsit&&a[b[i].place+1].ifsit) cnt=cnt*min(a[b[i].place-1].time,a[b[i].place+1].time)*(b[i].time-)
            }
        }
        
    }
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