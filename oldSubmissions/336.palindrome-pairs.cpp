class Solution {
public:
    bool ispal(const string& str){
        for(int i=0,j=str.size()-1;i<j;i++,j--){
            if(str[i]!=str[j])
                return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();++i){
            mp[string(rbegin(words[i]),rend(words[i]))] = i;
        }
        vector<vector<int>>ans;
        if(mp.count("")){
            for(int i=0;i<words.size();++i){
                if(ispal(words[i]) && words[i]!=""){
                    ans.push_back({mp[""],i});
                }
            }
        }
        for(int i=0;i<words.size();++i){
            for(int j=0;j<words[i].size();++j){
                string l = words[i].substr(0,j);
                string r = words[i].substr(j);
                if(mp.count(l) && mp[l]!=i && ispal(r)){
                    ans.push_back({i,mp[l]});
                }
                if(mp.count(r) && mp[r]!=i && ispal(l)){
                    ans.push_back({mp[r],i});
                }
            }
        }
        return ans;
    }
};
