class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int>nse(n);
stack<int>s;
for(int i=n-1;i>=0;i--){
    if(s.size()==0){
        nse.push_back(0);
    }
    else if(s.size()>0 && s.top()<=prices[i]){
        nse.push_back(s.top());
    }
    else if(s.size()>0 && s.top()>prices[i]){
        while(s.size()>0 && s.top()>prices[i]){
            s.pop();
        }
        if(s.size()==0){
            nse.push_back(0);
        }else{
            nse.push_back(s.top());
        }
    }

    s.push(prices[i]);
}
reverse(nse.begin(),nse.end());

vector<int>discount(n);
for(int i=0;i<n;i++){
    discount[i] = prices[i]-nse[i];
}
return discount;
    }
};