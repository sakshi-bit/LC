class Solution {
public:
    int reverse(int x) {
        int rev=0;
        int digit;
        while(x){
        if(rev<INT_MIN/10 || rev>INT_MAX/10){
            return 0;
        }else{
            digit=x%10;
            rev = rev*10+digit;
            x= x/10;
        }
        }
      
        return rev;
    }
};