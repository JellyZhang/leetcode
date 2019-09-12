class Solution {
public:
    string int2str(long long x){
        string ans = "";
        if(x<0){
            ans+="-";
            return ans+int2str(-x);
        }
        else if(x==0)
            return "0";
        while(x){
            ans+=x%10+'0';
            x/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int p = 0;
        int q = 0;
        vector<long long> lbs;
        vector<long long> ubs;
        lbs.push_back(lower);
        while(p<nums.size()){
            q = p;
            while(q<nums.size() && (long long)nums[q]-nums[p]==p-q){
                q++;
            }
            q--;
            lbs.push_back((long long)nums[q]+1);
            ubs.push_back((long long)nums[p]-1);
            p = q+1;
        }
        ubs.push_back(upper);
        vector<string> ans;
        for(int i=0;i<lbs.size();++i){
            string temp = "";
            long long lo = lbs[i];
            long long hi = ubs[i];
            if(hi==lo){
                temp+=int2str(hi);
                ans.push_back(temp);
            }
            else if(hi>lo){
                temp+=int2str(lo);
                temp+="->";
                temp+=int2str(hi);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
