#include<iostream>
#include<vector>
#include<cmath>
#include<map>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int z=0;z<t;z++){
        int n,k,x;
        cin>>n>>k>>x;
        vector<int>vecp(n);
        vector<int>vecx;
        multimap<int,int,greater<int>>mp;
        for(int j=0;j<n;j++){
            cin>>vecp[j];
        }
        sort(vecp.begin(),vecp.end());
        vecx.push_back(0);
        vecx.push_back(x);
        for(int i=0;i<n-1;i++){
            vecx.push_back(vecp[i]);
            if((vecp[i]+vecp[i+1])/2<=x)vecx.push_back((vecp[i]+vecp[i+1])/2);
            if((vecp[i]+vecp[i+1])/2+1<=x)vecx.push_back((vecp[i]+vecp[i+1])/2+1);
            if((vecp[i]+vecp[i+1])/2-1>=0)vecx.push_back((vecp[i]+vecp[i+1])/2-1);
        }
        vecx.push_back(vecp[n-1]);
        if(vecp[n-1]!=x&&(x+vecp[n-1])/2<=x)vecx.push_back((x+vecp[n-1])/2);
        if(vecp[n-1]!=x&&(x+vecp[n-1])/2+1<=x)vecx.push_back((x+vecp[n-1])/2+1);
        if(vecp[n-1]!=x&&(x+vecp[n-1])/2-1>=0)vecx.push_back((x+vecp[n-1])/2-1);
        if(vecp[0]!=0)vecx.push_back((vecp[0])/2);
        if(vecp[0]!=0&&(vecp[0])/2+1<=x)vecx.push_back((vecp[0])/2+1);
        if(vecp[0]!=0&&(vecp[0])/2-1>=0)vecx.push_back((vecp[0])/2-1);
        if((vecp[n-2]+vecp[n-1])/2<=x)vecx.push_back((vecp[n-2]+vecp[n-1])/2);
        if((vecp[n-2]+vecp[n-1])/2+1<=x)vecx.push_back((vecp[n-2]+vecp[n-1])/2+1);
        if((vecp[n-2]+vecp[n-1])/2-1>=0)vecx.push_back((vecp[n-2]+vecp[n-1])/2-1);
        sort(vecx.begin(),vecx.end());
        auto last=unique(vecx.begin(),vecx.end());
        vecx.erase(last,vecx.end());
        auto it=vecx.begin();
        
        while(it!=vecx.end()){
            
            int m=INT_MAX;
            for(int kt=0;kt<n;kt++){
                int m_curr=abs(vecp[kt]-*it);
                m=min(m,m_curr);
            }
            mp.insert({m,*it});
            it++;
        }
        
        int count=0;
        for(auto it=mp.begin();it!=mp.end()&&count<k;count++,it++){
            cout<<it->second<<endl;
        }
    }
    return 0;
}