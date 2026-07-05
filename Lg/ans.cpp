#include<bits/stdc++.h>
using namespace std;
typedef long long ll;           //P2672

int main(){
    int n;
    cin>>n;
    vector<int>s(n),a(n);
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<n;i++) cin>>a[i];
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>res(n,0);
    int temp=0;
    for(int i=0;i<n;i++){
        if(i==0) temp=2*s[0]+a[0];
        else{
            temp=max({temp,2*(s[i]-s[i-1])})
        }
        
    }
    return 0;
}