class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i=0;i<=n-1;i++){
            if(mpp.find(target-nums[i]) != mpp.end()){
                ans.push_back(mpp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            else{
                mpp[nums[i]]=i;
            }
        }
        return ans;
    }
};