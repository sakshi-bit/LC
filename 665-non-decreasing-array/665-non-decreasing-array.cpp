class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int change = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                if(change++==1) return false;
                if(i<2 || nums[i-2]<=nums[i])
                    nums[i-1] = nums[i];
                else
                    nums[i] = nums[i-1];
            }
        }
        return true;
    }
};