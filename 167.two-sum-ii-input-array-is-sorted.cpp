class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size()<=1)
            return {};
        int p = 0;
        int q = numbers.size()-1; 
        while(p<q){
            if(numbers[p]+numbers[q]==target){
                break;
            }
            if(numbers[p]+numbers[q]>target){
                q--;
            }
            else{
                p++;
            }
        }
        return {p+1,q+1};
    }
};
