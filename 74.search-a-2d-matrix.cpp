class Solution {
public:
    // []
    // [[]]
    // target < m[0][0]
    // target > m[lastone]
    // target between m[0][last] and m[1][first]
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows==0){
            return false;
        }
        int cols = matrix[0].size();
        if(cols==0){
            return false;
        }

        // lower_bound search
        int first = 0;
        int last = rows-1;
        int middle;
        while(first<=last){
            middle = (first+last)>>1;
            if(matrix[middle][0] <= target){
                first = middle+1;
            }
            else if(matrix[middle][0] > target){
                last = middle-1;
            }
        }
        int row = last;
        if(row==-1){
            return false;
        }
        first = 0;
        last = cols-1;
        while(first<=last){
            middle = (first+last)>>1;
            if(matrix[row][middle]>=target){
                last = middle -1;
            }
            else if(matrix[row][middle]<target){
                first = middle+1;
            }
        }
        if(first==cols){
            return false;
        }
        if(matrix[row][first]==target){
            return true;
        }
        return false;

    }
};
