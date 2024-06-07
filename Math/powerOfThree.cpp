class Solution {
public:
    bool isPowerOfThree(int n) {
        int remainder;
        if(n<=0){
            return false;
        }
        if(n==1){
            return true;
        }
        while(n>1){
            remainder = n%3;
            if(remainder!=0){
                return false;
            }
            n = n/3;
        }
        return true;
    }
};