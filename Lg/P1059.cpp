#include<iostream>
#include<set>
#include<algorithm>
using namespace std;      //simple

int main(){
    int n,x;
    cin>>n;
    set<int>st;
    for(int i=0;i<n;i++){
        cin>>x;
        st.insert(x);
    }
    cout<<st.size()<<endl;
    for(auto it:st){
        cout<<it<<' ';
    }
    return 0;
}