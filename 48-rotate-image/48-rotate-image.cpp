class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //Transpose of the given matrix
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                /*int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;*/
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //reverse of the transposed matrix
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};