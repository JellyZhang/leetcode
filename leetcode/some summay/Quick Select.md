```cpp
 int findK(vector<int>& nums, int start, int end, int target){
        int pivot = nums[start];
        int lo = start;
        int hi = end;
        while(lo < hi){
            while(lo < hi && nums[hi] >= pivot) hi--;
            nums[lo] = nums[hi];
            while(lo < hi && nums[lo] < pivot) lo++;
            nums[hi] = nums[lo];
        }
        nums[lo] = pivot;
        if(lo == target){
            return nums[lo];
        }else if(lo < target){
            return findK(nums, lo+1, end, target);
        }else{
            return findK(nums, start, lo-1, target);
        }
    }
```

