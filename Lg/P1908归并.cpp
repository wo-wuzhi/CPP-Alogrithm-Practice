#include<iostream>
#include<vector>        //归并排序（p1309同）
using namespace std;

long long count=0;

void merge(vector<int> &num,int l,int mid,int r){
    int i=l,j=mid+1,k=0;
    vector<int>temp(r-l+1);
    while(i<=mid&&j<=r){
        if(num[i]<=num[j]){
            temp[k++]=num[i++];
        }else{
            count+=mid-i+1;
            temp[k++]=num[j++];
        }
    }
    while(i<=mid) temp[k++]=num[i++];
    while(j<=r) temp[k++]=num[j++];
    for(int p=0;p<temp.size();p++){
        num[l+p]=temp[p];
    }
}

void solve(vector<int> &num,int l,int r){
    if(r-l+1<=1) return;
    int mid=l+(r-l)/2;
    solve(num,l,mid);
    solve(num,mid+1,r);
    merge(num,l,mid,r);
}

int main(){
    int n;
    cin>>n;
    vector<int>num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    solve(num,0,n-1);
    cout<<count<<endl;
    return 0;
}