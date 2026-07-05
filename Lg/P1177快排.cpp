#include<iostream>
#include<vector>
#include<algorithm>       //快排
using namespace std;

void swap(int &a,int &b){
    int temp=b;
    b=a;
    a=temp;
}

void qsort(vector<int>&arr,int low,int high){
    if(low>=high) return;
    int mid=arr[(low+high)/2];
    int i=low,j=high;
    while(i<=j){
        while(arr[i]<mid){
            i++;
        }
        while(arr[j]>mid){
            j--;
        }
        if(i<=j) {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        
    }
    qsort(arr,low,j);
    qsort(arr,i,high);
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    qsort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}