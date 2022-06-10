class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        int i=0,j=0;
        unordered_set<char> set;
        int n=s.size();
        while(i<n && j<n){
            if(set.find(s[j])==set.end()){
                set.insert(s[j++]);
                res=max(res,j-i);
            }else{
                set.erase(s[i++]);
                
            }
        }
        return res;
    }
};