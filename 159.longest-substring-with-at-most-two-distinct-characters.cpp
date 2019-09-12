class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.size()<=2)
            return s.size();
        int p;
        int q = 1;
        int ans = 0;
        int temp_before = 1;
        while(q<s.size() && s[q]==s[q-1]){
            temp_before++;
            q++;
        }
        if(q==s.size())
            return s.size();
        p = q - 1;
        char first = s[p];
        char second = s[q];
        while(true){
            //cout<<first<<" "<<second<<" "<<temp_before<<endl;
            while(q<s.size() && s[q]==second){
                q++;
            }
            if(q==s.size()){
                //end of string
                ans = max(ans,temp_before + q-p-1);
                break;
            }
            else if(s[q]==first){
                temp_before += (q-p-1);
                swap(first,second);
                p = q-1;
            }
            else{
                ans = max(ans,temp_before+q-p-1);
                first = second;
                second = s[q];
                temp_before = q-p-1;
                p = q-1;
            }
        }
        return ans;
    }
};
