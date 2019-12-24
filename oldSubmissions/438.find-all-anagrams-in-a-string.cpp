/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> times,curTimes;
        for(char& ch:p){
            times[ch]++;
        }
        int i = 0;
        int j = 0;
        vector<int> ans;
        while(j<s.size()){
            if(times.count(s[j])==0){
                j = i = j+1;
                curTimes.clear();
                continue;
            }
            curTimes[s[j]]++;
            while(curTimes[s[j]] > times[s[j]]){
                curTimes[s[i]]--;
                i++;
            }
            if(j-i+1 == p.size()){
                ans.push_back(i);
            }
            j++;
        }
        return ans;
    }
};
// @lc code=end
