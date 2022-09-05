class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]++;
        int cnt=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem = sum%k;
            if(rem<0){
                rem = rem+k;
            }
           if(mpp.find(rem)!=mpp.end()){
               cnt+=mpp[rem];
           }
            
            mpp[rem]++;
        }
        
        return cnt;
    }
};