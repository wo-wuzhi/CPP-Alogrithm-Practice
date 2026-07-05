#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    long long c;
    cin>>n>>c>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int j=0;
    while(j<n&&a[j]<=c) {
        if(k>0&&a[j]<c){
            if(k<c-a[j]){c+=k+a[j];k=0;}
            else {k-=c-a[j];c+=c;}
        }else c+=a[j];
        j++;
    }
    cout<<c<<endl;
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