class Solution {
public:
    int maximum69Number (int num) {
        vector<int> v;
        while(num){
            v.insert(v.begin(),num%10);
            num/=10;
        }
        
        for(int i=0;i<v.size();i++){
            if(v[i]==6){
                v[i]=9;
                break;
            }
        }
        int result = 0;
        for (auto d : v)  
        {
           result = result * 10 + d;
        }
        return result;
    }
};