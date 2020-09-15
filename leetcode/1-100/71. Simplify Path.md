> Given an **absolute path** for a file (Unix-style), simplify it. Or in other words, convert it to the **canonical path**.
>
> In a UNIX-style file system, a period `.` refers to the current directory. Furthermore, a double period `..` moves the directory up a level.
>
> Note that the returned canonical path must always begin with a slash `/`, and there must be only a single slash `/` between two directory names. The last directory name (if it exists) **must not** end with a trailing `/`. Also, the canonical path must be the **shortest** string representing the absolute path.
>
>  
>
> **Example 1:**
>
> ```
> Input: "/home/"
> Output: "/home"
> Explanation: Note that there is no trailing slash after the last directory name.
> ```
>
> **Example 2:**
>
> ```
> Input: "/../"
> Output: "/"
> Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
> ```
>
> **Example 3:**
>
> ```
> Input: "/home//foo/"
> Output: "/home/foo"
> Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
> ```
>
> **Example 4:**
>
> ```
> Input: "/a/./b/../../c/"
> Output: "/c"
> ```
>
> **Example 5:**
>
> ```
> Input: "/a/../../b/../c//.//"
> Output: "/c"
> ```
>
> **Example 6:**
>
> ```
> Input: "/a//b////c/d//././/.."
> Output: "/a/b/c"
> ```

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> res;
        split(path, "/", res);
        vector<string> dirs;
        for(const string& part:res){
            if(part == "." || part == "") continue;
            if(part == ".."){
                if(dirs.size() > 0) dirs.pop_back();
                continue;
            }
            dirs.push_back(part);
        }
        if(dirs.size() == 0) return "/";
        string ans = "";
        for(const auto& dir:dirs){
            ans += "/" + dir;
        }
        return ans;
    }
    void split(const string& str, const string& delim, vector<string>& res){
        int prev = 0, curr;
        curr = str.find_first_of(delim);
        while(curr != string::npos){
            res.push_back(str.substr(prev, curr - prev));
            prev = curr + delim.size();
            curr = str.find_first_of(delim, prev);
        }
        res.push_back(str.substr(prev));
    }
};
```

1. split by "/"

2. 

   - if dir_name == "." or "" then do nothing.
   - if dir_name == ".." then pop one level
   - else push one level

   