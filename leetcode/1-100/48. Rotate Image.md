> You are given an *n* x *n* 2D matrix representing an image.
>
> Rotate the image by 90 degrees (clockwise).
>
> **Note:**
>
> You have to rotate the image [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm), which means you have to modify the input 2D matrix directly. **DO NOT** allocate another 2D matrix and do the rotation.



```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n/2;++j){
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }

};
```

1. transpose
2. reverse every row