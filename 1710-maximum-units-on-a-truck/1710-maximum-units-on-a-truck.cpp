class Solution {
public:
    //sorting numberOfUnitsPerBox in decreasing order 
    static bool mySort(vector<int>&a,vector<int>&b){
        return a[1]>b[1];
            
    
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),mySort);
        int ans=0;
        for(auto box: boxTypes){
            int x = min(box[0],truckSize);
            ans = ans+(x*box[1]);
            truckSize = truckSize-x;
            if(truckSize<0)
                break;
            
        }
        
        return ans;
       
    }
};