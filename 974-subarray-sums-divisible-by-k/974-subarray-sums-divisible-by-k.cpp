class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0;
        int i=0;
        int n = nums.size();
        int sum=0;
        int rem=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        while(i<n){
            sum=sum+nums[i++];
            rem=sum%k;
            if(rem<0){
                rem=rem+k;
            }
            if(mpp.find(rem)!=mpp.end()){
                count+=mpp[rem];
            }
            
            mpp[rem]++;
        }
        
        return count;
    }
};