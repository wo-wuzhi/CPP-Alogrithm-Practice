#include<bits/stdc++.h>
using namespace std;         //sp

int main(){
    int m,n;
    cin>>m>>n;
    vector<int>t(n);
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    sort(t.begin(),t.end());
    int i=0,count=0;
    for(int j=n-1;j>=i;j--){
        int temp=t[j];
        while(temp+t[i]<=m){
            temp+=t[i];
            i++;
        }
        count++;
    }
    cout<<count;
    return 0;
}