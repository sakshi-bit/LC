class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(i==0 || nums[i]!=nums[i-1]){
            int j=nums[i+1], low = i+1,high=n-1;
            int sum = 0-nums[i];
            while(low<high){
                if(nums[low]+nums[high]==sum){
                    vector<int>v;
                    v.push_back(nums[low]);
                    v.push_back(nums[high]);
                    v.push_back(nums[i]);
                    ans.push_back(v);
                    v.clear();
                    
                    
                    while(low<high && nums[low]==nums[low+1]) low++;
                    while(low<high && nums[high]==nums[high-1]) high--;
                    
                    low++;
                    high--;
                }else
                    if(nums[low]+nums[high]<sum)
                        low++;
                    else
                        high--;
                    
                }
            }
            
        }
        return ans;
    }
};