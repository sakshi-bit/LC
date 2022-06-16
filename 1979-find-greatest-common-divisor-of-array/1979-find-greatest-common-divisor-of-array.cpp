class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(maxi<nums[i]){
                maxi = nums[i];
            }
        }
        
         for(int i=0;i<nums.size();i++){
        
        if(mini>nums[i]){
                mini = nums[i];
            }
         }
        int gcd=1;
        for(int i=1;i<=mini;i++){
            if(mini%i==0 && maxi%i==0){
                
                    gcd = i;
                
            }
            
        }
        if(mini==maxi){
            return mini;
        }
        return gcd;
    }
};