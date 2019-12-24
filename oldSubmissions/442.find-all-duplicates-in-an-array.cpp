/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int index = 0;
        while(index<nums.size()){
            int posToPut = nums[index]-1;
            if(nums[posToPut] != posToPut + 1){
                swap(nums[posToPut],nums[index]);
            }
            else{
                index++;
            }
        }
        vector<int> duplicateNums;
        for(int i=0;i<nums.size();++i){
            if(nums[i] != i+1)
                duplicateNums.push_back(nums[i]);
        }
        return duplicateNums;
        
    }
};
// @lc code=end
