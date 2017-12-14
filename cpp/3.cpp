#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int result=0;
        set<char>set1;
        while(j!=s.size()){
            if(set1.find(s[j])==set1.end()){
                set1.insert(s[j]);
                j++;
            }else{
                result=max(result,j-i);
                set1.erase(s[i]);
                i++;
            }
        }
        result=max(result,j-i);
        return result;

    }
};

int main(){
    string a;
    cin>>a;
    Solution s;
    cout<<s.lengthOfLongestSubstring(a);
    return 0;
}
