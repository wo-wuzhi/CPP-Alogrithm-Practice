#include<bits/stdc++.h>   //（p1378同）
using namespace std;  //dfs+字符串  dfs常用于解决：枚举所有解，回溯类，判断存在性问题

void dfs(string head,vector<string>&a,int* ans,int cur,vector<int>&arr){
    if(cur>*ans) *ans=cur;
    for(int i=0;i<a.size();i++){
        for(int j=min({head.size(),a[i].size()});j>=1;j--){
            string hou=head.substr(head.size()-j,j);
            string qian=a[i].substr(0,j);
            if(head.size()!=1&&j==min({head.size(),a[i].size()})) continue;
            if(hou==qian&&arr[i]>0){
                arr[i]--;
                dfs(a[i],a,ans,cur+a[i].size()-hou.size(),arr);
                arr[i]++;
            }
        }
    }
}

int main(){
    int n;
    int ans=1,cur=1;
    cin>>n;
    vector<string>a(n);
    vector<int>arr(n,2);
    string head;
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>head;
    dfs(head,a,&ans,cur,arr);
    cout<<ans;
    return 0;
}