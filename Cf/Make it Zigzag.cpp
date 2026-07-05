#include<iostream>
#include<vector>
using namespace std;

void solve(int n,vector<int>&arr1){
    int max=arr1[0],count=0;
    vector<int>arr2=arr1;
    for(int i=1;i<n-1;i++){
        if(max<arr2[i]){
            max=arr2[i];
        }
        if(i%2!=0){
            if(arr1[i]<=arr1[i-1]||arr1[i]<=arr1[i+1]){
                if(max<=arr1[i-1]){
                    count++;
                    
                }
                if(max<=arr1[i+1]){
                    count+=arr1[i+1]-max+1;
                    arr1[i+1]=max-1;
                }
            }
        }
    }
    if(max<arr2[n-1]) max=arr2[n-1];
    if((n-1)%2!=0){
        if(arr1[n-1]<=arr1[n-2]){
            if(max<=arr1[n-2]){
                count++;
                
            }
        }
    }
    cout<<count<<endl;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int>arr1(n);
        for(int j=0;j<n;j++){
            cin>>arr1[j];
        }
        solve(n,arr1);
    }
    return 0;
}