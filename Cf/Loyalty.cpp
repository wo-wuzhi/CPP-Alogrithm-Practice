#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;

void slove(int n,int x){
    long long Sum=0,p=0,sum=0;
    vector<int>arr(n),arr2;
    deque<int>dq;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        Sum+=arr[i];
        dq.push_back(arr[i]);
    }
    if(Sum<x){
        cout<<0<<endl;
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
            
        }
        cout<<endl;
        return;
    }
    while(!dq.empty()){
        if(sum+dq.front()<x){
            sum+=dq.front();
            arr2.push_back(dq.front());
            dq.pop_front();
        }else{
            sum+=dq.back();
            p+=dq.back();
            sum=sum-x;
            arr2.push_back(dq.back());
            dq.pop_back();
        }
    }
    cout<<p<<endl;
    for(int i=0;i<n;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,x;
        cin>>n>>x;
        slove(n,x);
    }
    return 0;
}