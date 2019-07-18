#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(0==nums.size()){
            return 0;
        }
        int i=0,j=0;
        for(;i<nums.size();i++){
            if(nums.at(i)!=val){
                nums.at(j++)=nums.at(i);
            }
        }
        return j;
    }
};
