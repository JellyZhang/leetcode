/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> daysToWait(T.size(),0);
        stack<int> stk;
        for(int i=0;i<T.size();++i){
            while(!stk.empty() && T[i]>T[stk.top()]){
                daysToWait[stk.top()] = i-stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return daysToWait;
    }
};
// @lc code=end
