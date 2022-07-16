class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int idx=0;
        int n = intervals.size();
        //step 1
        //intervals smaller than the starting time are added as it is
        while(idx<intervals.size()){
            if(intervals[idx][0]<newInterval[0]){
                ans.push_back(intervals[idx]);
                idx++;
            }
            else{
                break;
            }
        }
        
        //step 2
        //if the ans list is empty then new interval is the first interval
        //check if we can merge the new interval with previous intervals
        if(ans.size()==0 || newInterval[0] > ans.back()[1]){
            ans.push_back(newInterval);
        }else{
            
            ans.back()[1] = max(ans.back()[1],newInterval[1]);
        }
        
        //step 3
        //check for remaining intervals
        while(idx<n){
            
            if(ans.back()[1]>=intervals[idx][0]){
                //merging
                ans.back()[1] = max(ans.back()[1],intervals[idx][1]);
            }else{
                ans.push_back(intervals[idx]);
            }
            idx++;
        }
        return ans;
    }
};