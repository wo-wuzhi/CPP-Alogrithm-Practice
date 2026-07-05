#include<iostream>
#include<set>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        multiset<char>mta;
        multiset<char>mtb;
        int check=0;
        for(int i=0;i<a.length();i++){
            mta.insert(a[i]);
            mtb.insert(b[i]);
        }
        for(int i=0;i<a.length();i++){
            if(mta.count(a[i])!=mtb.count(a[i])||mtb.find(a[i])==mtb.end()){
                cout<<"NO"<<endl;
                check=-1;
                break;
            }
        }
        if(check==0)
        cout<<"YES"<<endl;
    }
    return 0;
}