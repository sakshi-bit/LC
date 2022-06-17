class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        int remain;
        while(mini){
            remain = maxi % mini;
            maxi = mini;
            mini = remain;
        }
        return maxi;
    }
};