/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> ht;
        for(int num:nums){
            ht[num]++;
        }
        int ans = 0;
        for(const auto& kv:ht){
            if(kv.second == 1){
                ans = kv.first;
                break;
            }
        }
        return ans;
    }
};
// @lc code=end
