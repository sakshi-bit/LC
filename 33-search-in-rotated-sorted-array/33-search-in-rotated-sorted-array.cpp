class Solution {
public:
    int binarySearch(vector<int>& nums, int low , int high, int target){
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                high = mid-1;
                
            }else{
                low = mid+1;
            }
        }
        return -1;
    }
    
    int minElement(vector<int>& nums, int low, int high){
        int n = nums.size();
        while(low<=high){
            int mid = low+(high-low)/2;
            int next = (mid+1)%n;
            int prev = (mid+n-1)%n;
            if(nums[mid]<=nums[next] && nums[mid]<=nums[prev]){
                return mid;
            }else if(nums[mid]<=nums[high]){
                high = mid-1;
            }else if(nums[mid]>=nums[low]){
                low = mid+1;
            }
        }
        return 0;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int index = minElement(nums,0,n-1);
        int a = binarySearch(nums,0,index-1,target);
        int b = binarySearch(nums,index,n-1,target);
        if(a==-1 && b==-1 ){
            return -1;
        }
        if(a>=0){
            return a;
        }
        
        return b;
    }
};