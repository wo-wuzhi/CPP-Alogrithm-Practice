#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,cnt0=0;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){if(s[i]=='0')cnt0++;}
    vector<int>a;
    for(int i=0;i<n;i++){
        if(i<cnt0&&s[i]!='0') a.push_back(i+1);
        else if(i>=cnt0&&s[i]!='1') a.push_back(i+1);
    }
    if(a.empty()){cout<<"Bob"<<endl;return;}
    else{
        cout<<"Alice"<<endl<<a.size()<<"\n";
        for(auto it:a){cout<<it<<' ';}
        cout<<endl;
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