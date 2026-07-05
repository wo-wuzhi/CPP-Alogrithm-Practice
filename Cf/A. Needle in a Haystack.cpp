#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s,t;
    cin>>s>>t;
    map<char,int>ch;
    for(int i=0;i<t.length();i++){
        ch[t[i]]++;
    }
    for(int i=0;i<s.length();i++){
        ch[s[i]]--;
        if(ch[s[i]]<0){cout<<"Impossible"<<endl;return;}
    }
    int p=0;
    for(auto it=ch.begin();it!=ch.end();){
        while(p!=s.length()&&it->first-'a'>=s[p]-'a'){
            cout<<s[p];
            p++;
        }
        if(it->second==0){it++;continue;}
        cout<<it->first;
        it->second--;
        if(it->second==0) it++;
    }
    while(p!=s.length()){
        cout<<s[p];
        p++;
    }
    cout<<endl;
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