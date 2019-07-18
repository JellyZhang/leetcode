#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(0==nums.size()){
            return 0;
        }
        unsigned long i=0,j=0;
        for(;i<nums.size();i++){
            if(nums.at(i)>nums.at(j)){
                ++j;
                nums.at(j)= nums.at(i);
            }
        }
        //nums.resize(j+1);
        return (j+1);
    }
};
