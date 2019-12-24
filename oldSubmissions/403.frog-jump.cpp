/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */

// @lc code=start
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,unordered_set<int>> dp;
        unordered_set<int> setStone(stones.begin(),stones.end());
        if(stones[1] != 1){
            return false;
        }
        dp[1] = {1};
        for(int i=1;i<stones.size();++i){
            for(int j:dp[stones[i]]){
                for(int k=-1;k<=1;++k){
                    int temp = j + k;
                    if(temp>0 && setStone.count(stones[i]+temp)>0)
                        dp[stones[i]+temp].insert(temp);
                }
            }
        }
        return dp[stones.back()].size()>0;
    }
};
// @lc code=end
