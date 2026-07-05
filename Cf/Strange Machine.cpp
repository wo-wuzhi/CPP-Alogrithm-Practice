#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>&qa,vector<char>&mn,int q,int n,int check){
    if(check==0){
        int i=0;
        while(i<q){
            int count=0;
            for(int j=0;qa[i]!=0;j++){
                if(mn[j]=='A'){
                    qa[i]--;
                }else{
                    qa[i]/=2;
                }
                count++;
                if(j==n-1) j=-1;
            }
            cout<<count<<" ";
            i++;
        }
    }else if(check==-1){
        for(int i=0;i<q;i++){
            cout<<qa[i]<<" ";
        }
    }else if(check==-2){
        for(int i=0;i<q;i++){
            int count=0;
            while(qa[i]!=0){
                qa[i]/=2;
                count++;
            }
            cout<<count<<" ";
        }
    }
    
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,q;
        cin>>n>>q;
        vector<int>qa(q);
        vector<char>mn(n);
        int numa=n,numb=n,check=0;
        for(int i=0;i<n;i++){
            cin>>mn[i];
            if(mn[i]=='A') numa--;
            else numb--;
        }
        for(int i=0;i<q;i++){
            cin>>qa[i];
        }
        if(numa==0) check=-1;
        else if(numb==0) check=-2;
        solve(qa,mn,q,n,check);
    }
    return 0;
}