#include<iostream>
#include<algorithm>
using namespace std;      //sp

struct p{
    string name;
    int finals;
    int evas;
    char lead;
    char east;
    int papnum;
};

int main(){
    int t;
    cin>>t;
    p stu[t];
    for(int i=0;i<t;i++){
        cin>>stu[i].name>>stu[i].finals>>stu[i].evas>>stu[i].lead>>stu[i].east>>stu[i].papnum;
    }
    int maxm=0,sum=0,j=0;
    long long all=0;
    for(int i=0;i<t;i++){
        sum=0;
        if(stu[i].finals>80&&stu[i].papnum>=1){
            sum+=8000;
        }
        if(stu[i].finals>85&&stu[i].evas>80){
            sum+=4000;
            
        }
        if(stu[i].finals>90){
            sum+=2000;
            
        }
        if(stu[i].finals>85&&stu[i].east=='Y'){
            sum+=1000;
            
        }
        if(stu[i].evas>80&&stu[i].lead=='Y'){
            sum+=850;
            
        }
        all+=sum;
        if(sum>maxm){
            j=i;
            maxm=sum;
        }
        
    }
    cout<<stu[j].name<<endl<<maxm<<endl<<all<<endl;
    return 0;
}