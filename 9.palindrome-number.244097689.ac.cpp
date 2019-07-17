#include <vector>
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        std::vector<int> Nums;
        while(0!=x){
            Nums.push_back(x%10);
            x/=10;
        }
        for(size_t i=0;i<Nums.size()/2;i++){
            if(Nums.at(i)!=Nums.at(Nums.size()-i-1)){
                return false;
            } 
        }
        return true;
    }
};

