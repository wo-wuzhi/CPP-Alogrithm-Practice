#include<iostream>
#include<vector>
using namespace std;

bool check(int n,int k,int x){
    vector<int>a(x,0);
    
    for(int i=0;i<n;i++){
        a[i%x]++;
    }
    for(int i=0;i<x;i++){
        if(a[i]>k)return false;
    }
    return true;
}

void solve(){
    int k,x,n=2;
    cin>>k>>x;
    while(check(n,k,x)){
        n++;
    }
    cout<<n<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}