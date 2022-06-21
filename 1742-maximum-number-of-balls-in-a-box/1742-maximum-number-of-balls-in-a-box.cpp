class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int cnt[46] = {};
        for(int i=lowLimit;i<=highLimit;i++){
            int sum =0,temp=i;
            while(temp){
                sum=sum+temp%10;
                temp=temp/10;
            }
            cnt[sum]++;
        }
        return *max_element(begin(cnt),end(cnt));
    }
};