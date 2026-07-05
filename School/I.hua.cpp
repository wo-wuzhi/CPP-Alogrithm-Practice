#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(pair<ll,ll>&a,pair<ll,ll>&b){
    if(a.second!=b.second) return a.second>b.second;
    else return a.first>b.first;
}

int main(){
    ll n,k,ans=0;
    cin>>n>>k;
    vector<pair<ll,ll>>a(n);
    for(int i=0;i<n;i++){cin>>a[i].second;}
    for(int i=0;i<n;i++){cin>>a[i].first;}
    sort(a.begin(),a.end(),cmp);
    vector<bool>b(k+1,true);
    ll j=0,cnt=0,able=k;
    for(int i=0;i<n&&cnt<k;i++){
        ll cur=min(a[i].first,able);
        if(b[cur]){ b[cur]=false;if(!b[able])able--;}
        else{
            int t=cur-1,ch=-1;
            while(t>=1){
                if(b[t]) {b[t]=false;ch=1;break;}
                t--;
            }
            if(ch<0){j++; continue;}
        }
        ans+=a[j].second;
        j++;
        cnt++;

    }
    if(cnt==k)
    cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}