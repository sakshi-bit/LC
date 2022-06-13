class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
       
        int ans=0;
        for(int i=1;i<points.length;i++){
             int []current = points[i];
             int []previous = points[i-1];
            ans = ans+Math.max(Math.abs(current[1]-previous[1]),Math.abs(current[0]-previous[0]));
        }
        return ans;
    }
}