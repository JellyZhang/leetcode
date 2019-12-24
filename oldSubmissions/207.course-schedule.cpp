/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDgreeNum(numCourses,0);
        vector<vector<int>> outDegrees(numCourses);
        for(auto& prere:prerequisites){
            outDegrees[prere[1]].push_back(prere[0]);
            inDgreeNum[prere[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;++i){
            if(inDgreeNum[i] == 0)
                q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int cur = q.front();q.pop();
            cnt++;
            for(int post: outDegrees[cur]){
                inDgreeNum[post]--;
                if(inDgreeNum[post]==0)
                    q.push(post);
            }
        }
        if(cnt == numCourses)
            return true;
        return false;
    }
};
// @lc code=end
