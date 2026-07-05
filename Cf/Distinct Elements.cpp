#include<iostream>
#include<vector>
using namespace std;

void solve(const vector<long long>&arr1,vector<long long>&arr2,int n){
    if(arr1[n-1]==(long long)(1+n)*n/2){
        for(long long i=0;i<n;i++){
            cout<<i+1<<" ";
        }
        cout<<endl;
    }else{
        long long maxless=0;
        for(long long i=0;i<n;i++){
            long long maxorg=(2+i)*(i+1)/2;
            if(arr1[i]==maxorg-maxless){
                cout<<i+1<<" ";
                arr2.push_back(i+1);
            }else{
                long long temp=arr2[maxorg-arr1[i]-maxless-1];
                maxless=maxorg-arr1[i];
                cout<<temp<<" ";
                arr2.push_back(temp);
            }
        }
    }
    
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<long long>arr1(n),arr2;
        for(int j=0;j<n;j++){
            cin>>arr1[j];
        }
        solve(arr1,arr2,n);
    }
    return 0;
}