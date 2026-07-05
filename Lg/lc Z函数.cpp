#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>getz(string s){
        int n=s.length();
        vector<int>z(n,0);
        int l=0,r=0;
        for(int i=1;i<n;i++){
            if(i<=r){
                int k=i-l;
                z[i]=min(r-i+1,z[k]);
            }
            while(i+z[i]<n&&s[z[i]]==s[i+z[i]]){
                z[i]++;
            }
            if(i+z[i]-1>r){
                l=i;
                r=i+z[i]-1;
            }
        }
        return z;    //最大相同前后缀的数值
    }
    long long sumScores(string s) {
        vector<int>z=getz(s);
        long long ans=0;
        for(auto it:z){ ans+=it;}
        return ans+s.length();
    }
};