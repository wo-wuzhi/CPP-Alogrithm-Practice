#include<iostream>
#include<cmath>
#include<iomanip>           //二分常用于解决最大的最小值/最小的最大值
using namespace std;        //二分逼近求解三次方程的根，double确保精确，因精确度可能与0的比较会出错

double res(double x,double a,double b, double c,double d){
    return (float)a*x*x*x+b*x*x+c*x+d;
}

double solve(double l,double r,double rl,double rr,double a,double b,double c,double d){
    double mid=(l+r)/2.0;
    double rm=res(mid,a,b,c,d);
    while(fabs(rm)>1e-6&&fabs(r-l)>1e-8){
        if(rm*rl<0){
            r=mid;
            rr=rm;
            
        }else{
            l=mid;
            rl=rm;
            
        }
        mid=(r+l)/2.0;
        rm=res(mid,a,b,c,d);
    }
    return mid;
}



int main(){
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    double x[6]={0.0};
    int j=0;
    for(double i=-100.0;i<100.0;i+=1.0){
        double lres=res(i,a,b,c,d);
        double rres=res(i+1.0,a,b,c,d);
        if(fabs(lres)<1e-6) {
            x[j++]=i;
            
        }
        else if(lres*rres<0){
            x[j++]=solve(i,i+1.0,lres,rres,a,b,c,d);
        }
    }
    if(fabs(res(100.0,a,b,c,d))<1e-6) x[2]=100.0;
    for(int i=0;i<6;i++){
        x[i]=round(x[i]*100)/100.0;
    }
    cout<<fixed<<setprecision(2);
    int count=1;
    for(int i=0;i<6;i++){
        if(i==0) cout<<x[i]<<' ';
        else if(x[i-1]==x[i]){}
        else if(count<3){
            cout<<x[i]<<' ';
            count++;
        }
        
        
    }
    cout<<endl;
    
    return 0;
}