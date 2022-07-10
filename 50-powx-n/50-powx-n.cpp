class Solution {
public:
    double positivePow(double x , int n){
        if(n==0)
            return 1;
        
    double smallOutput = positivePow(x,n/2);
    if(n%2==0)
        return smallOutput * smallOutput;
    return x*smallOutput*smallOutput;
            
    }
    
    double negativePow(double x ,  int n){
        if(n==-1)
            return 1/x;
        
        double smallOutput = negativePow(x,n/2);
        if(n%2==0)
            return smallOutput * smallOutput;
        return (1/x)*smallOutput*smallOutput;
    }
    double myPow(double x, int n) {
        if(n>=0)
            return positivePow(x,n);
        return negativePow(x,n);
            
        
    }
};