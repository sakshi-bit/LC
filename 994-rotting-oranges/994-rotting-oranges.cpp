class node {
    public:
    int x,y,time;
    node(int _x,int _y,int _time){
        x=_x;
        y=_y;
        time=_time;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<node>rotten_queue;
        
        //step 1 find the fresh oranges count and put the rotten oranges indexes into the queue
        
        int freshOrangesCount = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    rotten_queue.push(node(i,j,0));
                }
                if(grid[i][j]!=0){
                    freshOrangesCount++;
                }
            }
        }
        
        //step 2 check whether fresh oranges count is 0 then we return 0
        
        if(freshOrangesCount==0){
            return 0;
        }
        
        //step 3 dfs in queue
        
      
        
        while(rotten_queue.size()){
            
            int r = rotten_queue.front().x;
            int c = rotten_queue.front().y;
            int curr_time = rotten_queue.front().time;
            
            rotten_queue.pop();
            
            
            
            freshOrangesCount--;
            
            int dx[] = {-1,1,0,0};
            int dy[] = {0,0,-1,1};
            
            for(int idx=0;idx<4;idx++){
                int new_r = r+dx[idx];
                int new_c = c+dy[idx];
                
                if(new_r>=0 && new_r<n && new_c>=0 && new_c<m && grid[new_r][new_c]==1){
                    rotten_queue.push(node(new_r,new_c,curr_time+1));
                    grid[new_r][new_c] = 2;
                }
            }
            
            if(freshOrangesCount==0){
                return curr_time;
            }
        }
        
        return -1;
    }
};