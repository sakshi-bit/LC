class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isrow = false;
        bool iscol = false;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        //step 1 check whether dummy array that is first array is true or not or has zero or not
        
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0){
                iscol = true;
            }
        }
        
        for(int j=0;j<m;j++){
            if(matrix[0][j]==0){
                isrow = true;
            }
        }
        
        //step 2 check for the remaining values whether they are zero or not if they are zero mark                  the dummy row and dummy col as zero
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        //step 3 traverse and check  row dummy array and make respective rows as zero
        
        for(int i=1;i<n;i++ ){
            if(matrix[i][0]==0){
                for(int j=0;j<m;j++){
                    matrix[i][j] = 0;
                }
            }
        }
        
        // step 4  traverse and check  row dummy array and make respective cols as zero
        
        for(int j=1;j<m;j++){
            if(matrix[0][j]==0){
                for(int i=0;i<n;i++){
                    matrix[i][j]= 0;
                }
            }
        }
        
        // step 5 check whether row = true and col = true
        
        if(isrow){
            for(int j=0;j<m;j++){
                matrix[0][j]=0;
            }
        }
        
        if(iscol){
            for(int i=0;i<n;i++){
                matrix[i][0] = 0;
            }
        }
        
    }
};