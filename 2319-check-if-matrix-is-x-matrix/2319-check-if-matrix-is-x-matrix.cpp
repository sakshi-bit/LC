class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        bool flag=1;
        int n = grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               if(i==j){
                   if(grid[i][j]>0){
                       flag =1;
                   }else{
                       flag = 0;
                       return false;
                   }
               }else
                
                if((i+j)==n-1){
                    if(grid[i][j]>0){
                        flag=1;
                    }else{
                        flag=0;
                        return false;
                    }
                }
                
                else{
                    if(grid[i][j]!=0){
                        flag=0;
                        return false;
                    }
                }
               
                
            
        }
    }
        return true;
    }
};