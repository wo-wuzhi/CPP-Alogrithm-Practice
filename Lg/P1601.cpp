#include<bits/stdc++.h>
using namespace std;        //sp高精度（a+b）    下有豆包优美解答

int main(){
    string a,b;
    cin>>a>>b;
    int len=max({a.size(),b.size()});
    while(a.size()<len) a='0'+a;
    while(b.size()<len) b='0'+b;
    int ch=-1;
    string ans;
    for(int i=len-1;i>=0;i--){
        char tp='0';
        if(ch>0) tp+='1'-'0';
        if((a[i]-'0')+(b[i]-'0')+(tp-'0')>'9'-'0'){
            if(ch<0) ch=-ch;
            ans.push_back((a[i]-'0')+(b[i]-'0')+(tp-'0')-10*('1'-'0')+'0');
        }else{
            if(ch>0) ch=-ch;
            ans.push_back((a[i]-'0')+(b[i]-'0')+(tp-'0')+'0');
        }
    }
    if(ch>0) ans=ans+'1';
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i];
    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b, ans;
    cin >> a >> b;
    
    // 补前导0，让两个字符串长度相同
    int len = max(a.size(), b.size());
    while (a.size() < len) a = '0' + a;
    while (b.size() < len) b = '0' + b;
    
    int carry = 0; // 进位，0表示无进位，1表示有进位（核心修正）
    // 从最后一位（最低位）向前遍历
    for (int i = len - 1; i >= 0; --i) {
        // 1. 把字符转成数字（关键：字符'0'-'9'转成0-9的数值）
        int num_a = a[i] - '0';
        int num_b = b[i] - '0';
        
        // 2. 计算当前位的总和（数字和 + 进位）
        int sum = num_a + num_b + carry;
        
        // 3. 当前位的结果：sum%10 转成字符，追加到ans末尾
        ans.push_back((sum % 10) + '0');
        
        // 4. 更新进位：sum>=10则进位1，否则0
        carry = sum / 10;
    }
    
    // 5. 如果最后还有进位，补充到结果中
    if (carry > 0) {
        ans.push_back('1');
    }
    
    // 6. 反转结果（因为我们是从低位到高位追加的，需要转回高位到低位）
    reverse(ans.begin(), ans.end());
    
    cout << ans << endl;
    return 0;
}
*/