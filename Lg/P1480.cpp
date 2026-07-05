#include<bits/stdc++.h>
using namespace std;              //高精度a/b

bool check(string tp,string b,int lenb){
    int lentp=tp.size();
    if(lentp<lenb) return false;
    else if(lentp==lenb){
        int i=0,ch=-1;
        while(i<lenb){
            if(tp[i]-'0'>b[i]-'0') return true;
            else if(tp[i]-'0'==b[i]-'0') i++;
            else return false;
        }
    }
    return true;
}

string cheng(int x,string b,int lenb){
    int add=0;
    string res;
    for(int i=lenb-1;i>=0;i--){
        int nb=b[i]-'0';
        res+=(nb*x+add)%10+'0';
        add=(nb*x+add-(nb*x+add)%10)/10;
    }
    if(add!=0) res+=add+'0';
    reverse(res.begin(),res.end());
    return res;
}

char chu(string tp,string b,int lenb){
    char res;
    int i;
    for(i=1;i<10;i++){
        string k=cheng(i+1,b,lenb);
        int lenk=k.size();
        if(!check(tp,k,lenk)) break;
    }
    res=i+'0';
    return res;
}

string jian(string tp,string m){
    int add=0,len=tp.size();
    while(m.size()<len) m='0'+m;
    string res="\0";
    if(tp==m) return res;
    int nt,nm;
    for(int i=len-1;i>=0;i--){
        nt=tp[i]-'0';
        nm=m[i]-'0';
        if(nt-nm+add>=0){
            res+=nt-nm+add+'0';
            add=0;
        }
        else {
            res+=10+nt-nm+add+'0';
            add=-1;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    string a,b,tp,ans;
    cin>>a>>b;
    int lenb=b.size();
    int lena=a.size();
    if(!check(a,b,lenb)){
        cout<<0;
        return 0;
    }
    int cnt=0;
    for(int i=0;i<lena;i++){
        tp+=a[i];
        while(tp[0]=='0') tp.erase(0,1);
        if(tp.empty()){
            ans+='0';
            continue;
        }
        if(check(tp,b,lenb)){
            char t=chu(tp,b,lenb);
            int x=t-'0';
            ans+=t;
            tp=jian(tp,cheng(x,b,lenb));
        }else if(!ans.empty()){
            ans+='0';
        }
    }
    cout<<ans;
    return 0;
}