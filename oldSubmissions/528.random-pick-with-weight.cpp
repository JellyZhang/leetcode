/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

// @lc code=start
class Solution {
private:
    vector<int> prefixSum;

public:
    Solution(vector<int>& w) {
        prefixSum.assign(w.size()+1,0);
        for(int i=1;i<w.size()+1;++i){
            prefixSum[i] = prefixSum[i-1] + w[i-1];
        }
    }
    
    int pickIndex() {
        int randPick = rand() % prefixSum.back();
        //cout<<"ranpick "<<randPick<<endl;
        int pos = lower_bound(prefixSum.begin(),prefixSum.end(),randPick) - prefixSum.begin();
        if(prefixSum[pos] == randPick){
            return pos;
        }
        else {
            pos--;
            return pos;
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end
