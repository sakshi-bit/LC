class Solution {
    public int lengthOfLongestSubstring(String s) {
        int i=0,j=0;
        int n= s.length();
        int max=0;
        Set<Character> bucket = new HashSet<>();
        while(i<n && j<n ){
            if(!bucket.contains(s.charAt(j))){
                bucket.add(s.charAt(j++));
                max = Math.max(max,bucket.size());
            }else{
                bucket.remove(s.charAt(i++));
            }
        }
        return max;
    }
}