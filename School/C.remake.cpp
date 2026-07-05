#include<bits/stdc++.h>
using namespace std;

int main(){
    double a,b,c,d,e,f,g,x,y,z;
    cin>>a>>b>>c>>d>>e>>f>>g>>x>>y>>z;
    double cx=(x-a*d*x-a*e*y-a*f*z)/(a*g);
    double cy=(y-b*d*x-b*e*y-b*f*z)/(b*g);
    double cz=(z-c*d*x-c*e*y-c*f*z)/(c*g);
    cout<<cx<<cy<<cz<<endl;
    cout<<fixed<<setprecision(2)<<min({cx,cy,cz})<<endl;
    return 0;
}