class Solution {
public:
    int firstOcc(vector<int>& nums, int target, int start,int end ){
        if(start>end){
            return -1;
        }
        int mid = start+(end-start)/2;
        
            if(nums[mid]==target){
                int a1=firstOcc(nums,target,start,mid-1);
                return (a1!=-1)?a1:mid;
                
            }else if(nums[mid]>target){
                return max(firstOcc(nums,target,start,mid-1),-1);
            }
            else{
                return max(firstOcc(nums,target,mid+1,end),-1);
            }
        
    }
     int lastOcc(vector<int>& nums, int target, int start,int end ){
        if(start>end){
            return -1;
        }
        int mid = start+(end-start)/2;
       
            if(nums[mid]==target){
               return max(lastOcc(nums,target,mid+1,end),mid);
                
            }else if(nums[mid]>target){
                return max(lastOcc(nums,target,start,mid-1),-1);
            }
            else{
                return max(lastOcc(nums,target,mid+1,end),-1);
            }
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>answer(2);
        answer[0] = firstOcc(nums,target,0,nums.size()-1);
       answer[1] = lastOcc(nums,target,0,nums.size()-1);
        return answer;
        
    }
};