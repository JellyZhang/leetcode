/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
 */

// @lc code=start
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i =0;
        int mask[5] = {
            0b11111000,0b11110000,0b11100000,0b11000000,0b10000000
        };
        while(i<data.size()){
            int oldi = i;
            if((data[i]>>7) == 0){
                i++;
                continue;
            }
            for(int k=0;k<3;++k){
                if((data[i]&mask[k]) == mask[k+1]){
                    for(int j=1;j<=3-k;j++){
                        if(i+j>=data.size() || (data[i+j]&mask[3])!=mask[4]){
                            return false;
                        }
                    }
                    i+=4-k;
                    break;
                }
            }
            if(i == oldi){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
