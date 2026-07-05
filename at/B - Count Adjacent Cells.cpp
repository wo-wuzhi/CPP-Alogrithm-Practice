#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int a,b;
    cin>>a>>b ;
    if(a==1&&b==1){cout<<0<<endl;return 0;}
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            int x=0;
            if(i-1>=0) x++;
            if(i+1<a) x++;
            if(j-1>=0) x++;
            if(j+1<b) x++;
            cout<<x<<' ';
        }
        cout<<endl;
    }

    return 0;
}