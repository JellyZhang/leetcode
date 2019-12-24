class Trie {
private:
    vector<Trie*>nxt;
    bool isend;
public:
    /** Initialize your data structure here. */
    Trie() {
        nxt.assign(26,NULL);
        isend = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* p = this;
        for(int i=0;i<word.size();++i){
            int index = word[i]-'a';
            if(p->nxt[index]==NULL){
                p->nxt[index] = new Trie();
            }
            p=p->nxt[index];
        }
        p->isend = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* p = this;
        for(int i=0;i<word.size();++i){
            int index = word[i]-'a';
            if(p->nxt[index]==NULL){
                return false;
            }
            p = p->nxt[index];
        }
        return p->isend;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* p = this;
        for(int i=0;i<prefix.size();++i){
            int index = prefix[i]-'a';
            if(p->nxt[index]==NULL){
                return false;
            }
            p = p->nxt[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
