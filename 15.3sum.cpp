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
                        while(it1!=nums.end()-1 && *it1==*(it1-1))it1++;
                        while(it2!=nums.begin() && *it2==*(it2+1))it2--;
                }
                //cout<<"!"<<endl;
               // cout<<*it1<<"    "<<*it2<<endl;
            }
        }
        return ans;
    }
};