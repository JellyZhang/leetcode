class LRUCache {
private:
    unordered_map<int,int>hash;
    unordered_map<int,list<int>::iterator>iters;
    list<int>cache;
	int sz;
public:
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        int ans=-1;
        if(iters.count(key)){
            updatecache(key);
            ans = hash[key];
        }
        return ans;
    }
    
    void put(int key, int value) {
        if(cache.size()==sz && iters.count(key)==0){
            iters.erase(cache.back());
            hash.erase(cache.back());
            cache.pop_back();
        }
        updatecache(key);
        hash[key]=value;
    }
    void updatecache(int key){
        if(iters.count(key)){
            cache.erase(iters[key]);
        }
        cache.push_front(key);
        iters[key]=cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
