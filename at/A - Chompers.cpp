#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    string s;
    cin>>s>>n;
    string ans=s.substr(n,s.length()-2*n);
    cout<<ans<<endl;
    return 0;
}