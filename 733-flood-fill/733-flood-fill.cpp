class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int row = image.size();
        int col = image[0].size();
        
        int og_color = image[sr][sc];
        
        if(og_color == newColor){
            return image;
        }
        
        image[sr][sc] = newColor;
        if(sr > 0 && image[sr-1][sc] == og_color){
            floodFill(image,sr-1,sc,newColor);
        }
        
        if(sc>0 && image[sr][sc-1]==og_color){
            floodFill(image,sr,sc-1,newColor);
        }
        
        if(sr<row-1 && image[sr+1][sc]==og_color){
            floodFill(image,sr+1,sc,newColor);
        }
        
        if(sc<col-1 && image[sr][sc+1] == og_color){
            floodFill(image,sr,sc+1,newColor);
        }
        
        return image;
        
    }
};