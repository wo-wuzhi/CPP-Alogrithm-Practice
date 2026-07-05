#include<bits/stdc++.h>
using namespace std;

struct mem{
    int color,num;
    bool operator<(const mem&oth) const{
        return num<oth.num;
    }
};

void solve(){
    int a;
    cin>>a;
    vector<mem>b(a);
    for(int i=0;i<a;i++) {cin>>b[i].num;b[i].color=i+1;}
    if(a==1) {cout<<1<<endl;return;}
    sort(b.begin(),b.end());
    cout<<b[a-1].color<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        solve();
    }
}