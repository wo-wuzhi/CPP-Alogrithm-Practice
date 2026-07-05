#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int m,s,q,r;
    cin>>m>>s;
    q=s/m;
    r=s%m;
    vector<ll>p(m,0);
    vector<ll>sum(m+1,0);
    for(int i=0;i<m;i++){
        cin>>p[i];
        if(s>=q){
            p[i]+=q;
            s-=q;
        }else {p[i]+=s;s=0;}
        if(i<r){
            if(s>0) {p[i]++;s--;}
        }
        sum[i+1]=sum[i]+p[i];
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<endl;
    }
    return 0;
}