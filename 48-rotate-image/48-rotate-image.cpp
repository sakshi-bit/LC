class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /* 1. Transpose of the matrix */
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        /* 2. reverse every row */
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};