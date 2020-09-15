> Given an array of strings, group anagrams together.
>
> **Example:**
>
> ```
> Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
> Output:
> [
>   ["ate","eat","tea"],
>   ["nat","tan"],
>   ["bat"]
> ]
> ```
>
> **Note:**
>
> - All inputs will be in lowercase.
> - The order of your output does not matter.



```cpp
class Solution {
public:
    // ["", ""] should return [["",""]]
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string str:strs){
            string t = str;
            sort(t.begin(), t.end());
            mp[t].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto& kv:mp){
            ans.push_back(kv.second);
        }
        return ans;
    }
};
```

classification strings with their 「sorted form」。