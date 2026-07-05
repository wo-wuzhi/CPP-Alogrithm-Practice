#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[105][105];
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n-2;i++){
        for(int j=0;j<n-i-2;j++){
            int k=0;
            while(a[i+j+1][k]!=0){ 
                if(a[i][j]+a[i+j+1][k]<a[i][j+k+1]){
                    cout<<"Yes";return 0;
                }
                k++;
            }
        }
    }
    cout<<"No";
    return 0;
}