#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        sort(nums.begin(),nums.end());
        vector<int>::iterator it1,it2,it3;
        for(it3=begin(nums);it3!=end(nums);it3++){
            if(it3>nums.begin() && *(it3)==*(it3-1))continue;
            if(it3==end(nums))break;
            if(*it3>0)break;
            int target=0-*it3;
            //cout<<"target:"<<target<<endl;
            it1=it3+1;
            it2=nums.end()-1;
            while(it1<it2){
                if(*it1+*it2>target)it2--;
                else if(*it1+*it2<target)it1++;
                else {
                        vector<int> temp{*it1,*it2,*it3};
                        ans.push_back(temp);
                        it1++;
                        it2--;
                        while(*it1==*(it1-1))it1++;
                        while(*it2==*(it2+1))it2--;
                }
                //cout<<"!"<<endl;
               // cout<<*it1<<"    "<<*it2<<endl;
            }
        }
        return ans;
    }
};
int main(){

    //std::string a = "abc";
    //std::vector<std::string> strs;
    //strs.push_back("aaa");
    //strs.push_back("bbb");
//    for (auto i:strs){
//        std::cout<<i;
//    }
    Solution s;
    vector<int> nums = {2,-2,4};
    vector<vector<int>> t = s.threeSum(nums);
    cout<<t.size();

    return 0;
}