> N couples sit in 2N seats arranged in a row and want to hold hands. We want to know the minimum number of swaps so that every couple is sitting side by side. A *swap* consists of choosing **any** two people, then they stand up and switch seats.
>
> The people and seats are represented by an integer from `0` to `2N-1`, the couples are numbered in order, the first couple being `(0, 1)`, the second couple being `(2, 3)`, and so on with the last couple being `(2N-2, 2N-1)`.
>
> The couples' initial seating is given by `row[i]` being the value of the person who is initially sitting in the i-th seat.
>
> **Example 1:**
>
> ```
> Input: row = [0, 2, 1, 3]
> Output: 1
> Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
> ```
>
> 
>
> **Example 2:**
>
> ```
> Input: row = [3, 2, 0, 1]
> Output: 0
> Explanation: All couples are already seated side by side.
> ```
>
> 
>
> **Note:**
>
> 1. `len(row)` is even and in the range of `[4, 60]`.
> 2. `row` is guaranteed to be a permutation of `0...len(row)-1`.



```cpp
class Solution {
public:
    vector<int> father;
    int getFather(int x){
        if(father[x] == x) return x;
        return father[x] = getFather(father[x]);
    }
    void un(int x, int y){
        int father_x = getFather(x);
        int father_y = getFather(y);
        father[father_x] = father_y;
        return;
    }
    int count(){
        int ans = 0;
        unordered_set<int> s;
        for(int i=0;i<father.size();++i){
            if(!s.count(getFather(i))){
                ans++;
                s.insert(getFather(i));
            }
        }
        return ans;
        
    }
    int minSwapsCouples(vector<int>& row) {
        int n = row.size()/2;
        father.assign(n,0);
        for(int i=0;i<father.size();++i){
            father[i] = i;
        }
        for(int i=0;i<n;++i){
            un(row[2*i]/2, row[2*i+1]/2);
        }
        return n - count();
    }
};
```

