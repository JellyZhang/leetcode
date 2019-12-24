class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size()/2;++i){
            rotateLine(i,matrix.size()-2*i,matrix);
        }
    }
    void rotateLine(int start,int n,vector<vector<int>>& matrix){
        for(int i=0;i<n-1;++i){
            int temp = matrix[start][start+i];
            matrix[start][start+i] = matrix[start+n-1-i][start];
            matrix[start+n-1-i][start] = matrix[start+n-1][start+n-1-i];
            matrix[start+n-1][start+n-1-i] = matrix[start+i][start+n-1];
            matrix[start+i][start+n-1] = temp;
        }
            
    }
};
