class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int row = image.size();
        int col = image[0].size();
        
        int original_color = image[sr][sc];
        
        //step1 whether the original color is only the new color the we don't have to do anything
        
        if(original_color == color){
            return image;
        }
        
        //recursive solution
        
        //first assign the color to the source box
        
        image[sr][sc] = color;
        
        
        //when we go in up direction
        if(sr>0 && image[sr-1][sc]==original_color){
            floodFill(image,sr-1,sc,color);
        }
        
        //when we go in left direction
        if(sc>0 && image[sr][sc-1]==original_color){
             floodFill(image,sr,sc-1,color);
        }
        
        //when we go in down direction
        if(sr<row-1 && image[sr+1][sc]==original_color){
            floodFill(image,sr+1,sc,color);
        }
        
        //when we go right direction
        if(sc<col-1 && image[sr][sc+1] == original_color){
            floodFill(image,sr,sc+1,color);
        }
        
        return image;
        
    }
};