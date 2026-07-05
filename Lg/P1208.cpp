#include<bits/stdc++.h>
using namespace std;              //sp

struct sale{
    int p;
    int num;
};

bool cmp(sale a,sale b){
    if(a.p!=b.p) return a.p<b.p;
    return a.num>b.num;
}

int main(){
    int n,m,need;
    cin>>n>>m;
    sale s[m];
    need=n;
    for(int i=0;i<m;i++){
        cin>>s[i].p>>s[i].num;
    }
    int ans=0;
    sort(s,s+m,cmp);
    int i=0;
    while(need-s[i].num>0){
        need-=s[i].num;
        ans+=s[i].p*s[i].num;
        i++;
    }
    if(need==0) cout<<ans;
    else{
        ans+=s[i].p*need;
        cout<<ans;
    }
    return 0;
}