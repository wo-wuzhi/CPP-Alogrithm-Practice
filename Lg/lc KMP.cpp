#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findnext(string&a){
        int n=a.length();
        vector<int>next(n,0);
        int j=0;
        for(int i=1;i<n;i++){
            while(j>0&&a[i]!=a[j]){
                j=next[j-1];
            }
            if(a[i]==a[j]) j++;
            next[i]=j;
        }
        return next;
    }
    int strStr(string haystack, string needle) {
        int m=haystack.length(),n=needle.length(),j=0;
        vector<int>next=findnext(needle);
        for(int i=0;i<m;i++){
            while(j>0&&needle[j]!=haystack[i]){
                j=next[j-1];
            }
            if(needle[j]==haystack[i]) j++;
            if(j==n) return i-n+1;
        }
        return -1;
    }
};