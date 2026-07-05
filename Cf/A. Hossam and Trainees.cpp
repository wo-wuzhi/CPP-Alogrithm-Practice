#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int>p;
bool ch[35000];


void getp(){
    fill(ch,ch+35000,true);
    ch[0]=false,ch[1]=false;
    for(int i=3;i*i<=1e9;i+=2){
        if(ch[i]){
            for(int j=i*i;j<=sqrt(1e9);j+=i){
                ch[j]=false;
            }
        }
    }
    for(int i=2;i*i<=1e9;i++){
        if(ch[i]) p.push_back(i);
    }
}

void solve(){
    int n;
    cin>>n;
    map<int,int>a;
    vector<int>b(n);
    for(int i=0;i<n;i++)cin>>b[i];
    for(int x:b){
        for(int k:p){
            if(k*k>x)break;
            if(x%k==0){
                a[k]++;
                if(a[k]>1){cout<<"YES"<<endl;return;}
            }
            while(x%k==0)x/=k;
        }
        if(x>1){
            if(++a[x]>1){cout<<"YES"<<endl;return;}
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    getp();
    while(t>0){
        t--;
        solve();
    }
    return 0;
}