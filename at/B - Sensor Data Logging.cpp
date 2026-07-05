#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t,x;
    cin>>t>>x;
    vector<int>a(t+1,0);
    vector<int>b;
    for(int i=0;i<=t;i++)cin>>a[i];
    b.push_back(a[0]);
    cout<<0<<' '<<a[0]<<endl;
    int i=1;
    while(i<=t){
        if(abs(b[b.size()-1]-a[i])>=x){
            cout<<i<<' '<<a[i]<<endl;
            b.push_back(a[i]);
        }
        i++;
    }
    return 0;
}