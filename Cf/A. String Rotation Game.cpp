#include<bits/stdc++.h>
using namespace std;

int t;

int check(string a){
    int cnt=1;
    for(int i=1;i<a.size();i++){
        if(a[i]!=a[i-1]) cnt++;
    }
    return cnt;
}

void solve(){
    int n,ans[105]={0},cnt=1;
    cin>>n;
    string st;
    cin>>st;
    ans[0]=check(st);
    for(int i=0;i<st.size()-1;i++){
        if(st[i]==st[i+1]){
            string a=st.substr(0,i+1);
            string x=st.substr(i+1)+a;
            ans[cnt]=check(x);
            cnt++;
        }
    }
    sort(ans,ans+105);
    cout<<ans[104]<<endl;
}

int main(){
    cin>>t;
    while(t>0){
        t--;
        solve();
    }
    return 0;
}