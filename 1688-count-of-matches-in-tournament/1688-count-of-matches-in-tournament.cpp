class Solution {
public:
    int numberOfMatches(int n) {
         int teams=0;
        int matches=0;
        int ans=0;
        while(n!=1){
        if(n%2!=0){
            teams=(n-1)/2+1;
            matches=(n-1)/2;
        }else{
            teams=n/2;
            matches=n/2;
        }
           ans=ans+matches;
           n=teams;
    }
        return ans;
    }
};