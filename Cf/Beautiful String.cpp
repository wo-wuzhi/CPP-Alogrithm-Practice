#include<iostream>
#include<vector>
#include<string>

using namespace std;



int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,count=0;
        string s;
        cin>>n>>s;
        vector<int>arr(n,-1);
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                count++;
                arr[i]=i+1;
            }
        }
        cout<<count<<endl;
        if(count!=0){
            for(int i=0;i<n;i++){
                if(arr[i]!=-1)
                cout<<arr[i]<<' ';
            }
            cout<<endl;
        }
        
    }
    return 0;
}