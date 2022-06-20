class Solution {
public:
    int reverse(int num){
        
        int rev = 0;
        while(num){
           
            rev = rev*10+num%10;
            num=num/10;
        }
        return rev;
    }
    bool isSameAfterReversals(int num) {
        if(num==0)
            return true;
        int reversed1 = reverse(num);
        int reversed2 = reverse(reversed1);
        if(num==reversed2)
            return true;
        return false;
    }
};