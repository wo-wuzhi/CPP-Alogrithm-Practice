#include<bits/stdc++.h>
using namespace std;   //高精度乘法  高精度用于计算超大数  数字转字符串再转回数字

string cheng(char bi,string a,int lena){
    int nbi=bi-'0',add=0,ncur=0;
    string res;
    if(nbi==0) return res="0";
    for(int i=lena-1;i>=0;i--){
        ncur=(a[i]-'0')*nbi+add;
        add=(ncur-ncur%10)/10;
        res+=ncur%10+'0';
    }
    if(add!=0) res+=add+'0';
    reverse(res.begin(),res.end());
    return res;
}

string jia(string ans,string tp){
    int ad=0,len=tp.size();
    string res;
    while(ans.size()<len) ans='0'+ans;
    for(int i=len-1;i>=0;i--){
        int nt=tp[i]-'0',na=ans[i]-'0';
        res+=(nt+na+ad)%10+'0';
        if(nt+na+ad>=10) ad=1;
        else ad=0;
    }
    if(ad==1) res+='1';
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    string a,b,ans;
    cin>>a>>b;
    if(a.size()<b.size()){
        string temp=a;
        a=b;
        b=temp;
    }
    int lenb=b.size();
    int lena=a.size();
    int cnt0=-1;
    for(int i=lenb-1;i>=0;i--){
        cnt0++;
        string tp=cheng(b[i],a,lena);
        if(tp=="0") continue;
        int tpcnt0=cnt0;
        while(tpcnt0>0) {
            tp+='0';
            tpcnt0--;
        }
        
        ans=jia(ans,tp);
    }
    if(ans.empty()) ans="0";
    cout<<ans;
    return 0;
}