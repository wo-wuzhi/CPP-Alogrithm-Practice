#include<bits/stdc++.h>
using namespace std;            //高精度

int main(){
    string a,b;
    cin>>a>>b;
    if(a==b){
        cout<<0;
        return 0;
    }
    int lena=a.size();
    int lenb=b.size();
    int len=max({lena,lenb}),ch=1;
    if(lena<lenb) ch=-ch;
    else if(lena==lenb){
        int i=0;
        while(a[i]==b[i]&&i<len) i++;
        if(a[i]-'0'<b[i]-'0') ch=-ch;
    }
    while(a.size()<len) a='0'+a;
    while(b.size()<len) b='0'+b;
    int tp=0;
    string ans,temp;
    if(ch<0){
        temp=a;
        a=b;
        b=temp;
    }
    for(int i=len-1;i>=0;i--){
        int p=0;
        int na=a[i]-'0';
        int nb=b[i]-'0';
        if(tp==-1) {
            if(na>0) na--;
            else p=-1;
        }
        if(na<nb){
            ans.push_back(p+na+10-nb+'0');
            if(tp==0) tp=-1;
        }else if(na==0&&nb==0&&p==-1){
            tp=-1;
            ans.push_back('9');
        }else{
            ans.push_back(na-nb+'0');
            if(tp==-1) tp=0;
        }
    }
    int i=ans.size()-1;
    while(!ans.empty()&&ans[i]=='0'){
        ans.erase(i);
        i--;
    }
    if(ch<0) ans+='-';
    i=ans.size()-1;
    for(;i>=0;i--) cout<<ans[i];
    return 0;
}