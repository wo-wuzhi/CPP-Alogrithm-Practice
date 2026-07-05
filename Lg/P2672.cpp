#include<bits/stdc++.h>
using namespace std;               //贪心+线段树或贪心+小根堆

int pcmax;

int increase(pair<int,int>x){
    if(x.first<pcmax){                   //错误做法，虽然过了。。。
        return x.second;
    }else{
        return 2*(x.first-pcmax)+x.second;
    }
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>a[i].second;
    }
    long long cmax=0;
    auto t=a.end();
    for(auto it=a.begin();it!=a.end();it++){
        if(2*(it->first)+it->second>cmax){
            cmax=2*(it->first)+it->second;
            pcmax=it->first;
            t=it;
        }
    }
    a.erase(t);
    vector<int>aup(n-1);
    pair<int,int> aupmax={0,0};
    int ch;
    for(int i=0;i<n-1;i++){
        increase(a[i]);
        if(increase(a[i])==aupmax.second) {
            if(a[i].first<aupmax.first) {
                aupmax.first=a[i].first;
                ch=i;
            }
            
        }
        if(increase(a[i])>aupmax.second) 
        {
            aupmax=a[i];
            ch=i;
        }
    }
    aup[0]=increase(aupmax);
    if(pcmax<aupmax.first)
    pcmax=aupmax.first;
    auto shan=a.begin();
    for(int i=0;i<ch;i++) shan++;
    a.erase(shan);
    for(int i=1;i<n-1;i++){
        aup[i]=increase(a[i-1]);
    }
    sort(aup.begin(),aup.end(),greater<int>());
    cout<<cmax<<endl;
    for(int i=0;i<n-1;i++){
        cmax+=aup[i];
        cout<<cmax<<endl;
    }
    return 0;
}