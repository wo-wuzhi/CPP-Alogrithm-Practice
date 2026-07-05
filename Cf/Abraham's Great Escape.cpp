#include<iostream>
using namespace std;

void solve(int n,int k){
    
    if(k==n*n-1) {
        cout<<"NO"<<endl;
        return;
    }else if(k==n*n){
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<"U";
            }
            cout<<endl;
        }
    }else{
        int leavenum=n*n-k;
        int gonum=k;
        int ileave,jleave,check=0;
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(gonum>0){
                    cout<<"U";
                    gonum--;
                }else {
                    ileave=i;
                    jleave=j;
                    check=-1;
                    break;
                }
            }
            if(check==0)
            cout<<endl;
            else break;
        }
        if(jleave!=1&&jleave!=n){
            int tim=(n-jleave+1)/2;
            for(int i=0;i<tim;i++){
                cout<<"RL";
            }
            if(tim*2!=n-jleave+1) cout<<"L"<<endl;
            else cout<<endl;
            ileave++;
            jleave=1;
        }else if(jleave==n){
            cout<<"D"<<endl;
            ileave++;
            jleave=1;
        }
        int jo=0;
        if(n%2!=0) jo=-1;
        for(int i=ileave;i<=n;i++){
            for(int j=1;j<=n/2;j++){
                cout<<"RL";
            }
                if(jo==0) {cout<<endl;}
                else if(jo=-1) cout<<"L"<<endl;
            
        }
    }
}

int main(){
    int t;
    cin>>t;
    for(int num=0;num<t;num++){
        int n,k;
        cin>>n>>k;
        solve(n,k);
    }
    return 0;
}