#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0){
            return 0;
        }
        int p=0;
        int q=nums.size()-1;
        int mid = (p+q)>>1;
        while(p<=q){
            //cout<<p<<" "<<q<<endl;
            mid = (p+q)>>1;
            if(nums.at(mid)<target){
                p=mid+1;
            }
            else if(nums.at(mid)> target){
                q=mid-1;
            }
            else{
                return mid;
            }
        }
        //target only possible in [p,q];
        //when end with p=mid+1,means pos q is impossible, only possible in [p,+infinity); so insert at p;
        //when end with q=mid-1,like the former situation, but notice that when we insert at i,we push older num[i] to the right side.so in this situation ,
        //target only possible in (-infinity,q], we should insert into p(which is q+1);
        return p;
    }
};

//int main(){
    //Solution s;
    //vector<int> nums = {1,3,5,6};
    //cout<<s.searchInsert(nums,6);

    //return 0;
//}
