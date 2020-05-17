#### 4. Median of Two Sorted Arrays

> There are two sorted arrays **nums1** and **nums2** of size m and n respectively.
>
> Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
>
> You may assume **nums1** and **nums2** cannot be both empty.
>
> **Example 1:**
>
> ```
> nums1 = [1, 3]
> nums2 = [2]
> 
> The median is 2.0
> ```
>
> **Example 2:**
>
> ```
> nums1 = [1, 2]
> nums2 = [3, 4]
> 
> The median is (2 + 3)/2 = 2.5
> ```

```C++
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(n < m) return findMedianSortedArrays(nums2,nums1);
        if((m+n)%2 == 1) return findKth(nums1, nums2, (m+n)/2);
        return (findKth(nums1,nums2,(m+n-1)/2) + findKth(nums1,nums2,(m+n)/2))/2.0;
    }
    int findKth(vector<int>& nums1, vector<int>& nums2, int k){
        /*
        nums1:______i____
        nums2:___j__________
        第一个数组取索引i的位置，第二个取索引j的位置。
        当我们能保证i左边的i个数与j左边的j个数为最小的k个数，那么min(nums1[i],nums2[j])即为第k大的数
        如果要做到上述情况，那么需要 i+j == k && nums1[i] >= nums2[j-1] && nums2[j] >= nums1[i-1]
        可以对i的位置进行二分搜索，因为i+j==k，可以得出对应的k的位置，再根据是否达成条件来进行左移右移
        因为i增大时,nums1[i]就增大，nums2[j]就减小。
        因此当nums1[i] < nums2[j-1]时，需要右移i的位置。
        当nums2[j] < nums1[i-1]时，说明j太小，i太大，需要左移i的位置。
        因为i在变化时会涉及到数组边界，为了方便处理，两个数组最左和最右分别设置为负无穷和正无穷。显然这样不影响结果。
        现在判断i的变化范围
        当i==0时，nums2[j] >= nums1[i-1] ==负无穷,永远成立，因此i不可能会左移。因此i左界限为0
        当i==nums1.size()-1时，nums1[i] < nums2[j-1]可能成立，因此可能右移。
        当i==nums1.size()时，nums1[i]为正无穷。nums1[i]<nums2[j-1]不可能成立，此时不可能右移。因此i右界限为nums1.size();
        */
        #define A(i) (i < 0 ? INT_MIN : (i>=nums1.size()?INT_MAX:nums1[i]))
        #define B(i) (i < 0 ? INT_MIN : (i>=nums2.size()?INT_MAX:nums2[i]))
        int lo = 0;
        int hi = nums1.size();
        while(lo <= hi){
            int i = lo + (hi - lo)/2;
            int j = k - i;
            if(A(i) < B(j-1)){
                lo = i + 1;
            }else if(B(j) < A(i-1)){
                hi = i - 1;
            }else{
                return min(A(i),B(j));
            }
        }
        #undef A
        #undef B
        return -1;
    }
```

