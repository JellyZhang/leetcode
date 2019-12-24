/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> times;
        for(string& word:words){
            times[word]++;
        }
        priority_queue<pair<string,int>,vector<pair<string,int>>,myComp> pq;
        for(auto& kv:times){
            if(pq.size()<k){
                pq.push({kv.first,kv.second});
            } else if(times[pq.top().first] < kv.second || (times[pq.top().first] == kv.second && pq.top().first > kv.first)){
                pq.pop();
                pq.push({kv.first,kv.second});
            } 
        }
        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
    struct myComp{
        bool operator()(const pair<string,int>& x, const pair<string,int>& y){
            if(x.second != y.second)
                return x.second > y.second;
            else
                return x.first < y.first;
        }
    };
};
// @lc code=end
