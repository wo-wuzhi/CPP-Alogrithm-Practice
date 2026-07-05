#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin>>s;
    ll len=s.length(),cnt=0;
    for(ll i=0;i<len;i++){
        if(s[i]=='C'){
            cnt+=min(i+1,len-i);
        }
    }
    cout<<cnt<<endl;
    return 0;
}