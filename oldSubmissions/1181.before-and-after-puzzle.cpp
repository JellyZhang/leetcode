/*
 * @lc app=leetcode id=1181 lang=cpp
 *
 * [1181] Before and After Puzzle
 */

// @lc code=start
class Solution {
public:
    void mySplit(string& phrase,vector<string>& ans){
        stringstream ss(phrase);
        string token;
        while(getline(ss,token,' ')){
            ans.push_back(token);
        }
    }
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        vector<vector<string>> sentences(phrases.size(),vector<string>());
        for(int i=0;i<phrases.size();++i){
            mySplit(phrases[i],sentences[i]);
        }
        set<string>ans;
        for(int i=0;i<sentences.size();++i){
            for(int j=0;j<sentences.size();++j){
                if(i==j)
                    continue;
                if(sentences[i].back() == sentences[j].front()){
                    string temp = phrases[i];
                    for(int k=1;k<sentences[j].size();++k){
                        temp += " "+sentences[j][k];
                    }
                    ans.insert(temp);
                }
            }
        }
        vector<string> rtn(ans.begin(),ans.end());
        //sort(ans.begin(),ans.end());
        return rtn;
    }
};
// @lc code=end
