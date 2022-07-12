class Solution {
public:
    int gcd(int a,int b){
        if(b==0){
            return a;
        }
        
        return gcd(b,a%b);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int>mpp;
        for(int i=0;i<deck.size();i++){
            mpp[deck[i]]++;
        }
        
        int g = mpp[deck[0]];
        
        for(auto count:mpp){
            g = gcd(max(count.second,g),min(count.second,g));
        }
        
        if(g>1){
            return true;
        }
        return false;
    }
};