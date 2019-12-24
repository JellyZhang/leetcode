/*
 * @lc app=leetcode id=759 lang=cpp
 *
 * [759] Employee Free Time
 */

// @lc code=start
/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
public:
    vector<Interval*> employeeFreeTime(vector<vector<Interval*>> schedule) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,myComp> pq;
        int employeeNums = schedule.size();
        for(auto& employee:schedule){
            for(auto& inter:employee){
                pq.push({inter->start,1});
                pq.push({inter->end,-1});
            }
        }
        int cnt = 0;
        int startIdle = -1;
        vector<Interval*> ans;
        while(!pq.empty()){
            auto cur = pq.top();pq.pop();
            int oldcnt = cnt;
            cnt += cur.second;
            if(oldcnt == 1 && cnt == 0){
                startIdle = cur.first;
            }
            if(oldcnt == 0 && cnt == 1 && startIdle != -1){
                Interval* temp = new Interval(startIdle,cur.first);
                ans.push_back(temp);
            }
        }
        return ans;
        
    }
    struct myComp{
        bool operator()(const pair<int,int>& x, const pair<int,int>& y){
            if(x.first != y.first)
                return x.first>y.first;
            else
                return x.second<y.second;
        }
    };
};
// @lc code=end
