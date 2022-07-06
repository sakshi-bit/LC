class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        int n = s.length();
        int anagrams[26]={0};
        for(int i=0;i<n;i++){
            anagrams[s[i]-'a']++;
            anagrams[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(anagrams[i])
                return false;
        }
        
        return true;
    }
};