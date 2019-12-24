/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> rtn;
        for(int i=1;i<=n;++i)
            rtn.push_back(isFizzBuzz(i));
        return rtn;
    }
    string isFizzBuzz(int n){
        string ans = "";
        if(n%3==0)
            ans.append("Fizz");
        if(n%5==0)
            ans.append("Buzz");
        if(ans=="")
            ans = to_string(n);
        return ans;
    }
};
// @lc code=end
