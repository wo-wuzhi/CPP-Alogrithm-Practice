#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,p1=-1,p2;
    cin>>n;
    vector<int>a(2*n);
    for(int i=0;i<2*n;i++){
        cin>>a[i];
        if(a[i]==0){
            if(p1==-1)p1=i;
            else p2=i;
        }
    }
    int l=p1-1,r=p1+1,ans=0,temp=0;
    map<int,int>mp;
    mp[0]++;
    while(l>=0&&r<2*n){
        if(a[l]==a[r]){
            mp[a[l]]++;
            l--;r++;
        }else break;
    }
    while(mp[temp]!=0){
        temp++;
        ans=max(ans,temp);
    }
    l=p2-1,r=p2+1;
    mp.clear();
    mp[0]++;
    temp=0;
    while(l>=0&&r<2*n){
        if(a[l]==a[r]){
            mp[a[l]]++;
            l--;r++;
        }else break;
    }
    while(mp[temp]!=0){
        temp++;
        ans=max(ans,temp);
    }
    l=p1+1,r=p2-1,temp=0;
    mp.clear();
    mp[0]++;
    bool ch1=true;
    while(l>=0&&r<2*n&&l<=r){
        if(a[l]==a[r]){
            mp[a[l]]++;
            l++;r--;
        }else{ch1=false; break;}
    }
    l=p1-1,r=p2+1;
    if(ch1){
        while(l>=0&&r<2*n&&l<r){
            if(a[l]==a[r]){
                mp[a[l]]++;
                l--;r++;
            }else break;
        }
        while(mp[temp]!=0){
            temp++;
            ans=max(ans,temp);
        }
    }
    
    cout<<ans<<endl;
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