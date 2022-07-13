class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        
        int rows = board.size();
        int cols = board[0].size();
        
        int ans = 0;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                
                //check whether you are standing on the battle field 
                //check top should not exist or there should not be an 'x' above me
                //check left should not exist or left element should not be 'x'
                
                if(board[i][j]=='X' && (i==0 || board[i-1][j]!='X') && (j==0 || board[i][j-1]!='X')){
                    ans++;
                }
                
            }
        }
        
        return ans;
        
    }
};