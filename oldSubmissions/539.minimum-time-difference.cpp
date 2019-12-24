/*
 * @lc app=leetcode id=539 lang=cpp
 *
 * [539] Minimum Time Difference
 */

// @lc code=start
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        for(const string& timep:timePoints){
            times.push_back(time2int(timep));
        }
        sort(times.begin(),times.end());
        times.push_back(times.front()+24*60);
        int ans = 24*60+5;
        for(int i=0;i+1<times.size();++i){
            ans = min(ans,times[i+1]-times[i]);
        }
        ans = min(ans,times.back()-times.front());
        return ans;
    }
    int time2int(const string& time){
        int ans = 0;
        ans += 60*(stoi(time.substr(0,2)));
        ans += stoi(time.substr(3));
        return ans;
    }
};
// @lc code=end
