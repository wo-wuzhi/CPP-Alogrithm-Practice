#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string b;
    int j,k,cnta=0,cntb=0;
    cin>>b>>j>>k;
    vector<int>p;
    do{
        p.push_back(stoi(b));
    }while(next_permutation(b.begin(),b.end()));
    string m=to_string(p[j-1]),n=to_string(p[k-1]);
    for(int i=0;i<m.size();i++){
        if(m[i]==n[i]) cnta++;
    }
    cout<<cnta<<'A'<<b.size()-cnta<<'B'<<endl;
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