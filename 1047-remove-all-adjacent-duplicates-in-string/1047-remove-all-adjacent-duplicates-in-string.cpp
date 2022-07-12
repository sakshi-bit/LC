class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        for(auto i:s){
            if(res.size()==0 || res.back()!=i){
                res.push_back(i);
            }
            else{
                res.pop_back();
            }
        }
        
        return res;
        
        
    }
};