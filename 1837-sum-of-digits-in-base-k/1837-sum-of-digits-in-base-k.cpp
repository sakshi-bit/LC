class Solution {
public:
    int sumBase(int n, int k) {
        int digit=0;
        int sum=0;
        while(n>0){
            digit = n%k;
            n = n/k;
            sum=sum+digit;
            
        }
        return sum;
    }
};