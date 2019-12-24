class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> stones;
        for(char cha : J){
            stones.insert(cha);
        }
        int ans = 0;
        for(char cha : S){
            if(stones.count(cha)){
                ans++;
            }
        }
        return ans;
    }
};
