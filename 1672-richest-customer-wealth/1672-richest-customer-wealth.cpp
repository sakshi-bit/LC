class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int>wealth;
        
        for(int i=0;i<accounts.size();i++){
            int sum = 0;
           for(int j=0;j<accounts[i].size();j++){
               sum =sum+accounts[i][j];
               wealth.push_back(sum);
           }
        }
        int maxi = *max_element(wealth.begin(),wealth.end());
        return maxi;
    }
};