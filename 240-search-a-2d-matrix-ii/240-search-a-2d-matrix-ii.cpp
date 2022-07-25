class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int rowIndex=0;
        int colsIndex=cols-1;
        while(rowIndex<rows && colsIndex>=0){
            int element=matrix[rowIndex][colsIndex];
            if(element==target){
                return 1;
            }
            if(element>target){
                colsIndex--;
            }else{
                rowIndex++;
            }
        }
        return false;
    }
};