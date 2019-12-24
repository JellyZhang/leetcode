#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxyet=-1;
        while(i<j){
            maxyet = max(maxyet,(j-i)*min(height.at(i),height.at(j)));
            if(height.at(i)<height.at(j)){
                i++;
            }
            else{
                j--;
            }
        }
        return maxyet;
    }
};
