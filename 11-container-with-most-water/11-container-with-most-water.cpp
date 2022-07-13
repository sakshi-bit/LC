class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        int n = height.size();
        int l =0,r=n-1;
        for(int i=0;i<n;i++){
            int hl = height[l];
            int hr = height[r];
            int curr_water = min(hl,hr) * (r-l);
            if(curr_water > max_water){
                max_water = curr_water;
            }
            
            if(hl<=hr){
                l++;
            }
            if(hl>hr){
                r--;
            }
        }
        return max_water;
    }
};