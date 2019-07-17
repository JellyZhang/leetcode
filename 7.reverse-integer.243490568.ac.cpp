#include <vector>
#include <math.h>
class Solution {
public:
    int reverse(int x) {
        int max_int = pow(2,31)-1;
        if(x==-max_int -1){
            return 0;
        }
        std::vector<int> Nums;
        bool is_negative=false;
        if(x<0){
           is_negative = true;
           x=-x;
        }
        else{
            is_negative = false;
        }
        while(x!=0){
            Nums.push_back(x%10);
            x/=10;
        }
        int ans=0;
        for (auto it = Nums.begin(); it!=Nums.end();it++){
            if(ans<=max_int/10 && (*it)<=max_int-ans*10){
                ans =ans*10+(*it);
            }
            else{
                return 0;
            }   
        }
        if(is_negative){
            ans = -ans;
        }


    return ans;
    }
};

