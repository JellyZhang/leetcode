> Given a collection of intervals, merge all overlapping intervals.
>
> **Example 1:**
>
> ```
> Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
> Output: [[1,6],[8,10],[15,18]]
> Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
> ```
>
> **Example 2:**
>
> ```
> Input: intervals = [[1,4],[4,5]]
> Output: [[1,5]]
> Explanation: Intervals [1,4] and [4,5] are considered overlapping.
> ```
>
> **NOTE:** input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
>
>  
>
> **Constraints:**
>
> - `intervals[i][0] <= intervals[i][1]`



```cpp
typedef pair<int,int> pii;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pii> Nodes;
        for(auto& inter:intervals){
            Nodes.emplace_back(inter[0], 1);
            Nodes.emplace_back(inter[1], 0);
        }
        sort(Nodes.begin(), Nodes.end(), [](const pii& x, const pii& y){
            if(x.first == y.first){
                return x.second > y.second;
            }
            return x.first < y.first;
        });
        int cur = 0;
        int pos = -1;
        vector<vector<int>> ans;
        for(const auto& node:Nodes){
            if(node.second){
                if(cur++ == 0){
                    pos = node.first;
                }
            }else{
                if(--cur == 0){
                    ans.push_back({pos, node.first});
                }
            }
        }
        return ans;
        
    }
};
```



