#include<bits/stdc++.h>          //快速幂   a,a^2,a^4,a^8……
using namespace std;

long long solve(int a,int b,int p){
    if(b==0) return 1;
    long long res=solve(a,b/2,p);
    if(b%2==1) return res=res*res%p*a%p;
    return res*res%p;
}

int main(){
    long long a,b,p;
    cin>>a>>b>>p;
    cout<<a<<'^'<<b<<" mod "<<p<<'='<<solve(a,b,p);
    return 0;
}

/*
long long solve(int a,int b,int p){
    long long res=1;
    a=a%p;
    while(b){
        if(b&1==1) res=(res*a)%p;
        a=(a*a)%p;
        b>>1;
    }
}
*/