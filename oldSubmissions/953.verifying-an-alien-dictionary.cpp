class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> poses;
        for(int i=0;i<order.size();++i){
            poses[order[i]] = i;
        }
        for(int i=0;i+1<words.size();++i){
            if(compareTwoWords(words[i],words[i+1],poses))
                return false;
        }
        return true;
    }
    //true -> should exchange pos
    bool compareTwoWords(string& word1, string& word2, unordered_map<char,int>&poses){
        int i =0;
        while(i<word1.size() && i<word2.size()){
            if(word1[i]!=word2[i]){
                return poses[word1[i]]>poses[word2[i]];
            }
            i++;
        }
        if(i==word1.size())
            return false;
        return true;
    }
};
