#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,sum=0;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
    int tp=a[0];
    for(int i=1;i<n;i++){
        int temp=gcd(tp,a[i]);
        if(temp==a[i]){continue;}
        else if(temp==1) tp*=a[i];
        else{
            tp=tp*a[i]/temp;
        }
    }
    int m=0;
    for(int i=0;i<n;i++){
        m+=tp/a[i];
    }
    if(m>=tp){cout<<-1<<endl;return;}
    else{
        for(auto it:a){
            cout<<tp/it<<' ';
        }
        cout<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        solve();
    }
}