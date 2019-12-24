class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> vals;
    unordered_map<int,int>poses;

    RandomizedSet() {
        
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(poses.count(val)){
            return false;
        }
        poses[val] = vals.size();
        vals.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!poses.count(val)){
            return false;
        }
        int index = poses[val];
        poses[vals.back()] = poses[vals[index]];
        vals[index] = vals.back();
        vals.pop_back();
        poses.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand()%vals.size();
        return vals[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
