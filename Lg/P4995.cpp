#include<bits/stdc++.h>
using namespace std;         //sp

int main(){
    int n;
    long long ans=0;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ans+=a[n-1]*a[n-1];
    auto l=a.begin(),r=a.end()-1;
    int ch=-1;
    while(l<r){
        ans+=(*l-*r)*(*l-*r);
        if(ch<0) r--;
        else l++;
        ch=-ch;
    }
    cout<<ans;
    return 0;
}