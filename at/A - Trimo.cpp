#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    string s;
    cin>>n>>s;
    int i=0;
    while(i<s.length()&&s[i]=='o'){
        i++;
    }
    string ans=s.substr(i,s.length()-i);
    cout<<ans<<endl;
    return 0;
}