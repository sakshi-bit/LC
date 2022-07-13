class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>>mergedInterval;
        
        if(intervals.size()==0){
            return mergedInterval;
        }
        
        //step 1
        sort(intervals.begin(),intervals.end());
        //step 2
        vector<int>tempInterval = intervals[0];
        
        for(auto it: intervals){
            //1<=3 ===> 3 = max(3,3);;; 2<=3 ===> max(6,3) == 6 ====> (1,6)
            if(it[0]<=tempInterval[1]){
                tempInterval[1] = max(it[1],tempInterval[1]);
            }
            else{
                
                mergedInterval.push_back(tempInterval);
                tempInterval = it;
                
            }
        }
        
        mergedInterval.push_back(tempInterval);
        return mergedInterval;
        
    }
};