class Solution {
public:
     vector<int> nearestSmallestLeft(vector<int> heights){
        vector<int>left;
        stack<pair<int,int>>st;
        int pseudo=-1;
         
        for(int i=0;i<heights.size();i++){
            if(st.empty())
                left.push_back(pseudo);
            
            else if(st.size()>0 && st.top().first<heights[i])
                left.push_back(st.top().second);
            
            else if(st.size()>0 && st.top().first>=heights[i]){
                while(st.size()>0 && st.top().first>=heights[i])
                    st.pop();
                
                if(st.empty())
                    left.push_back(pseudo);
                else
                    left.push_back(st.top().second);
                
            }
            
            st.push({heights[i],i});
        }
        return left;
    }
    vector<int> nearestSmallestRight(vector<int> heights){
        vector<int>right;
        stack<pair<int,int>>st;
        
        
        int pseudo = heights.size();
        for(int i=heights.size()-1;i>=0;i--){
            if(st.empty())
                right.push_back(pseudo);
            
            else if(st.size()>0 && st.top().first<heights[i])
                right.push_back(st.top().second);
            
            else if(st.size()>0 && st.top().first>=heights[i]){
                while(st.size()>0 && st.top().first>=heights[i])
                    st.pop();
                
                if(st.empty())
                    right.push_back(pseudo);
                else
                    right.push_back(st.top().second);
                
            }
            
            st.push({heights[i],i});
        }
        
        return right;
    }
    int largestRectangleArea(vector<int>& heights) {
    vector<int> left = nearestSmallestLeft(heights);
    vector<int> right = nearestSmallestRight(heights);
    reverse(right.begin(),right.end());
       
       
        //width vector
        vector<int>width;
        
        
       int maxarea=-1;
		for(int i=0;i<heights.size();i++)
		{
			int width=right[i]-left[i]-1;
			maxarea=max(maxarea,width*heights[i]);
		}
		return maxarea;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
         int n = matrix.size();
        if(n==0)
            return 0;
        int m = matrix[0].size();
        
        int mx=0;
        vector<int>v(m,0);
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')
                     v[j]= v[j]+1;
                else
                   v[j]=0;
            }
            
            mx = max(mx,largestRectangleArea(v));
        }
        
        return mx;
        
        
        
    }  
        
        
        
        
        
        
    
};