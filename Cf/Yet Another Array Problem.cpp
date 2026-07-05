#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool checkzhi(int x){
    if(x%2==0)return false;
    for(int i=3;i<=sqrt(x);i+=2){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,x=2,check=-1;
        cin>>n;
        vector<long long>vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        while(true){
            for(int i=0;i<n;i++){
                if(vec[i]%x!=0){
                    check=1;
                    break;
                }
            }
            if(check==1){
                cout<<x<<endl;
                break;
            }else{
                do{
                    x++;
                }while(!checkzhi(x));
                
            }
        }
        
    }
}