#include<iostream>
using namespace std;

int num(int need){
    int num=1;
    while(need>1){
        need>>=1;
        num<<=1;
    }
    return num;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        int t=a|b;
        int p=a&b;
        int need=t^p;
        if(a==b){
            cout<<"0\n";
        }
        else if((t^a)>a){
            cout<<-1<<endl;
        }else if(need<a){
            cout<<"1\n"<<need<<endl;
        }else{
            cout<<"2\n"<<(need-num(need))<<" "<<num(need)<<" \n";
        }
    }
    
    return 0;
}