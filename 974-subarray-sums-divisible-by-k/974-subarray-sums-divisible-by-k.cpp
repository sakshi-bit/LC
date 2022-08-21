class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int,int>mpp;
        int count=0;
        mpp[0]++;
        
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
           int rem=sum%k;
            if(rem<0){
                rem=rem+k;
            }
            if(mpp.find(rem)!=mpp.end()){
                count=count+mpp[rem];
            }
            mpp[rem]++;
        }
        return count;
    }
};