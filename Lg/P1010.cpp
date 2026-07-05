#include<bits/stdc++.h>
using namespace std;        //分治

void solve(int n){
    if(n==0) return;
    if(n==1) {
        cout<<"2(0)";
        return;
    }
    if(n==3){
        cout<<"2+2(0)";
        return;
    }
    int k=0,temp=1;
    while(temp*2<=n){
        temp*=2;
        k++;
    }
    int rest=n-temp;
    if(k==1) cout<<"2";
    else{
        cout<<"2(";
        solve(k);
        cout<<')';
        if(rest>0) {
            cout<<"+";
            solve(rest);
        }
    }
}

int main(){
    int n;
    cin>>n;
    solve(n);
    return 0;
}