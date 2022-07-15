class Solution {
public:
    string removeDuplicateLetters(string s) {
        //step 1 initialization
        string res;
        stack<char>st;
        set<char>present;
        unordered_map<char,int>last;
        int n =s.length();
        
        //step 2 make last occurrence map
        
        
        for(int i=0;i<n;i++){
            last[s[i]]=i;
        }
        
        //step 3 check whether the character already present in set because it should be unique
        
        for(int i=0;i<n;i++){
            if(present.find(s[i])!=present.end()){
                continue;
            }
        
        
        //step 4 final check ====> important check
        
        while(!st.empty() && st.top()>s[i] && last[st.top()]>i){
            
            present.erase(st.top());
            st.pop();
        }
        
        st.push(s[i]);
        present.insert(s[i]);
       }   
        
        //step 5 append the stack to a string
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};