class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;
        sort(nums.begin(),nums.end());
        vector<int>::iterator it1,it2,it3,it4;
        for(it3=begin(nums);it3!=end(nums);it3++){
            for(it4=it3+1;it4!=end(nums);++it4){
                cout<<*it3<<","<<*it4<<";";
                int t=target-*it3-*it4;
                //cout<<"target:"<<target<<endl;
                it1=it4+1;
                it2=nums.end()-1;
                while(it1<it2){
                    if(*it1+*it2>t)it2--;
                    else if(*it1+*it2<t)it1++;
                    else {
                            vector<int> temp{*it1,*it2,*it3,*it4};
                            ans.push_back(temp);
                            it1++;
                            it2--;
                            while(it1!=nums.end()-1 && *it1==*(it1-1))it1++;
                            while(it2!=nums.begin() && *it2==*(it2+1))it2--;
                    }
                    //cout<<"!"<<endl;
                   // cout<<*it1<<"    "<<*it2<<endl;
                }
                while(it4!=nums.end()-1 && *(it4)==*(it4+1) )++it4;
            }
            while(it3!=nums.end()-1 && *(it3)==*(it3+1))++it3;
        }
        return ans;
    }
};
