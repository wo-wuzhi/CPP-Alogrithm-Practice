#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin>>s;
    int cntr=0,cntc=0,cntx=0,n=s.length(),l=0,r=0,p=INT_MAX;
    ll ans=0;
    int cnt=0;
    for(;r<n;r++){
        
        if(s[r]=='r'){ cntr++;p=r;}
        else if(cntr!=0&&s[r]=='c') cntc++;
        else if(cntr!=0&&cntc!=0&&s[r]=='x') cntx++;
        if(cntr&&cntc&&cntx){ans+=(n-r)*(p+1-l);}
        while(cntr&&cntc&&cntx){
        
            if(l>=p){
                if(s[l]=='r') cntr--;
                else if(s[l]=='c') cntc--;
                else if(s[l]=='x') cntx--;
                if(cntr==0) cntc=0;
                if(cntc==0) cntx=0;
            }
            l++;
        }
    }
    cout<<ans<<endl;
    return 0;
}