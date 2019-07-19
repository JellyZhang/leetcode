class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int maxyet=INT_MAX;
        int ans=-1;
        sort(nums.begin(),nums.end());
        vector<int>::iterator it1,it2,it3;
        for(it3=begin(nums);it3!=end(nums);it3++){
           // if(it3>nums.begin() && *(it3)==*(it3-1))continue;
            //if(it3==end(nums))break;
            //if(*it3>0)break;
            //cout<<"target:"<<target<<endl;
            it1=it3+1;
            it2=nums.end()-1;
            while(it1<it2){
                if(abs(*it1+*it2+*it3-target)<maxyet){
                    ans=*it1+*it2+*it3;
                    maxyet=abs(*it1+*it2+*it3-target);
                }
                if(*it1+*it2+*it3>=target)it2--;
                else if(*it1+*it2+*it3<target)it1++;
                //cout<<"!"<<endl;
               // cout<<*it1<<"    "<<*it2<<endl;
            }
        }
        return ans;
    }
};
