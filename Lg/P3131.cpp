#include<bits/stdc++.h>
using namespace std;            //sp前缀和

int main(){
    int n,i;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n+1,0);
    for(int j=0;j<n;j++){
        cin>>a[j];
        b[j+1]=(b[j]+a[j])%7;
    }
    int ans=0;
    for(int i=0;i<=6;i++){
        int l=0,r=n;
        while(b[l]!=i&&l<r) l++;
        while(b[r]!=i&&r>l) r--;
        ans=max({ans,r-l});
    }
    cout<<ans;
    return 0;
}