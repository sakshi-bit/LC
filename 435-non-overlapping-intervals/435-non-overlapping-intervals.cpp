class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        int n = intervals.size();
        int left = 0;
        int right = 1;
        int count=0;
        
        while(right<n){
            
            //case 1 non overlappping case
            
            if(intervals[left][1]<=intervals[right][0]){
                left = right;
                right +=1;
            }
            
            //case 2 remove right interval
            
            else if(intervals[left][1]<=intervals[right][1]){
                count++;
                right+=1;
            }
            
            //case 3 remove left interval
            
            else if(intervals[left][1]>intervals[right][1]){
                count++;
                left = right;
                right+=1;
            }
                
            
        }
        return count;
    }
};