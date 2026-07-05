#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin>>n;
  multiset<int>a;
  for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    if(x==1){
        a.insert(y);
    }else{
        auto it=a.upper_bound(y);
        a.erase(a.begin(),it);
    }
    cout<<a.size()<<endl;
  }
  return 0;
}