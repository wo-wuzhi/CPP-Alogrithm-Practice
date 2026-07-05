#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>&a,pair<int,int>&b){
    double ra=(double)a.first/a.second;
    double rb=(double)b.first/b.second;
    return ra<rb;
}

int main(){
    int m;
    cin>>m;
    vector<pair<int,int>>a(m);
    for(int i=0;i<m;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end(),cmp);
    int n;cin>>n;
    bool ch=false;
    if((double)a[m-1].first/a[m-1].second<=1.0) ch=true;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(ch){ cout<<x<<endl;continue;}
        else{
            int t=m-1;
            while(t>=0&&a[t].first>x)t--;
            if(t==-1){ cout<<x<<endl;continue;}
            cout<<x%a[t].first+a[t].second*(x-x%a[t].first)/a[t].first<<endl;
        } 
    }
    return 0;
}