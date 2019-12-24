/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    vector<int> nums;
    int index ;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        index = 0;
        nums = decode(nestedList);
    }
    int next() {
        return nums[index++];
    }

    bool hasNext() {
        if(index==nums.size())
            return false;
        return true;
    }
    vector<int> decode(vector<NestedInteger> ni){
        vector<int>ans;
        for(int i=0;i<ni.size();++i){
            if(ni[i].isInteger()){
                ans.push_back(ni[i].getInteger());
            }else{
                vector<int> temp = decode(ni[i].getList());
                ans.insert(ans.end(),begin(temp),end(temp));
            }
        }
        return ans;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
