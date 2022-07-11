class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>right(n);
        right[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            right[i] = right[i+1]*nums[i+1];
        }
        
        int left_product=1;
        for(int i=0;i<n;i++){
            right[i] = right[i]*left_product;
            left_product = left_product*nums[i];
        }
        return right;
    }
};