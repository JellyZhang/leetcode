#include <algorithm>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(n>m){
            return findMedianSortedArrays(nums2,nums1);
        }
        //m longer than n
        if(n==0){
            if(m%2==0){
                return 1.0*(nums1.at(m/2-1)+nums1.at(m/2))/2.0;
            }
            else{
                return 1.0*nums1.at(m/2);
            }
        }
        int i,j;
        cout<<nums1.at(0)<<"~"<<nums2.at(n/2);
        if(nums1.at(0)>nums2.at((n-1)/2)){
            j = std::lower_bound(begin(nums2),end(nums2),nums1.at(0))-begin(nums2);
            i = 0 ;
            cout<<"one:"<<i<<","<<j<<";";
        }
        else if(nums1.at(0)<=nums2.at((n-1)/2) && nums1.at((m-1)/2)> nums2.at((n-1)/2)){
            j = (n-1)/2;
            i = std::lower_bound(begin(nums1),end(nums1),nums2.at((n-1)/2))-begin(nums1); 
            cout<<"two:"<<i<<","<<j<<";";

        }
        else if(nums1.at((m-1)/2)<=nums2.at((n-1)/2)){
            j = 0;
            i = (m-1)/2;
            cout<<"three:"<<i<<","<<j<<";";
        }
        if(i!=0){
            --i;
        }
        if(j!=0){
            --j;
        }
        int limit = (m+n)/2;
        if((m+n)%2 ==0){
            --limit;
        }
        while(i+j<limit){
            if(i == m ){
                ++j;
            }
            else if(j==n){
                ++i;
            }
            else if(nums1.at(i)<nums2.at(j)){
                ++i;
            }
            else{
                ++j;
            }
        }
        if((m+n)%2==0){
            int first;
            if(i==m){
                first = nums2.at(j);
            }
            else if(j==n){
                first = nums1.at(i);
            }
            else{
                first = min(nums1.at(i),nums2.at(j));
            }

            if(i == m ){
                ++j;
            }
            else if(j==n){
                ++i;
            }
            else if(nums1.at(i)<nums2.at(j)){
                ++i;
            }
            else{
                ++j;
            }
            int second;
            if(i==m){
                second= nums2.at(j);
            }
            else if(j==n){
                second = nums1.at(i);
            }
            else{
                second = min(nums1.at(i),nums2.at(j));
            }

            return (1.0*first+second)/2.0;

        }
        else{
            int first;
            if(i==m){
                first = nums2.at(j);
            }
            else if(j==n){
                first = nums1.at(i);
            }
            else{
                first = min(nums1.at(i),nums2.at(j));
            }
            return 1.0*first;
        }

    }
};
