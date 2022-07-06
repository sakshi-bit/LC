class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>anagrams;
        if(s.length()!=t.length())
            return false;
        int n = s.length();
        for(int i=0;i<n;i++){
            anagrams[s[i]]++;
            anagrams[t[i]]--;
        }
        for(auto count : anagrams){
            if(count.second)
                return 0;
        }
        return true;
    }
};