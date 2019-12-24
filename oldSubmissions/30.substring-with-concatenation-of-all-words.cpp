class Solution {
public:
    //"aa",[]
    //"",[1,2]
    vector<int> findSubstring(string s, vector<string>& words) {
        int nums = words.size();
        int len1 = s.size();
        //corner
        if(nums==0||s==0){
            return {};
        }
        int len2 = words[0].size();
        if(len2*nums<len1){
            return {};
        }
        vector<int>ans;
        for(int i=0;i<len2;++i){
            int j=0;

        }
        
    }
};
