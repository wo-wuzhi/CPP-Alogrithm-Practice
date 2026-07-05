#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    string x;
    cin>>n>>x;
    int i=0,j=0;
    set<pair<int,int>>cur;
    cur.insert({0,0});
    for(auto c:x){
        set<pair<int,int>>next;
        for(auto [p,q]:cur){
            char lc=(p==0?'a':'b');
            char rc;
            if(n%2==1){
                rc=q%2==0?'a':'b';
            }else{
                rc=q%2==0?'b':'a';
            }
            if(c=='?'||c==lc){
                next.insert({p^1,q});
            }
            if(c=='?'||c==rc){
                next.insert({p,q^1});
            }
        }
        if(next.empty()){cout<<"NO"<<endl;return;}
        cur=move(next);
    }
    cout<<"YES"<<endl;
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