/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> times(27,0);
        for(const char& task:tasks){
            times[task-'A']++;
        }
        sort(times.begin(),times.end(),[](int a,int b){
                return a>b;
                });
        int idle_blocks = (times[0]-1) * n;
        for(int i=1;i<27 && times[i]>0;++i){
            if(times[i] == times[0])
                idle_blocks -= (times[i]-1);
            else 
                idle_blocks -= times[i];
        }
        int ans = 0;
        if(idle_blocks > 0)
            ans = tasks.size() + idle_blocks;
        else
            ans = tasks.size();
        return ans;
    }
};
// @lc code=end
