/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for(int i=0;i<asteroids.size();++i){
            //cout<<i<<endl;
            if(stk.empty() || stk.back()<0 || asteroids[i]>0){
                stk.push_back(asteroids[i]);
            }else if(asteroids[i]+stk.back()==0){
                stk.pop_back();
            }else if(asteroids[i]+stk.back()<0){
                stk.pop_back();
                --i;
            }
        }
        //vector<int> ans;
        //while(!stk.empty()){
            //ans.push_back(stk.top());
            //stk.pop();
        //}
        //reverse(begin(ans),end(ans));
        return stk;
    }
};
// @lc code=end
