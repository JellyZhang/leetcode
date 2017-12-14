#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0)return "";
        int ans_left=0,ans_len=1;
        for(int i=0;i<s.size();i++){
            int left=i,right=i;
            while(s[right]==s[right+1])right++;
            while(s[left]==s[right]){
                if(left==0||right==s.size()-1)break;
                left--;
                right++;
            }
            if(s[left]!=s[right]) {
                left++;
                right--;
            }
            if(right-left+1>ans_len){
                ans_len=right-left+1;
                ans_left=left;
                //cout<<left<<right<<endl;
                //cout<<ans_left<<"  "<<i<<" "<<ans_len<<endl;
            }
        }

        return s.substr(ans_left,ans_len);
    }
};

int main(){
    string a;
    cin>>a;
    Solution s;
    cout<<s.longestPalindrome(a);
    return 0;
}
