/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> ht;
        for(int num:nums){
            ht[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,myComp> pq(ht.begin(),ht.end());
        vector<int> ans;
        while(!pq.empty() && k){
            ans.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return ans;
    }
    struct myComp{
        bool operator()(const pair<int,int>& x, const pair<int,int>& y){
            return x.second<y.second;
        }
    };
};
// @lc code=end
