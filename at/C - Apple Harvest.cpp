#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,ans=0;
    cin>>n>>k;
    vector<int>a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int l=0,r=0,cnt=0;
    for(r=0;r<n;r++){
        while(r>l&&a[r]-a[l]>k){
            l++;
            
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans<<endl;
    return 0;
}