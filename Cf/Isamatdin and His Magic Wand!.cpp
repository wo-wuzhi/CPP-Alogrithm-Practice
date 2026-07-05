#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,count=0;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        for(int i=0;i<n;i++){
            if(vec[i]%2==0){
                count++;
            }
        }
        if(count==n||count==0){
            for(int i=0;i<n;i++){
                cout<<vec[i]<<endl;
            }
        }else{
            sort(vec.begin(),vec.end());
            for(int i=0;i<n;i++){
                cout<<vec[i]<<endl;
            }
        }
    }
}