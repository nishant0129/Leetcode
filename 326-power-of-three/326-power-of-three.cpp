class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
     // int ldiv=(int)pow(3, floor(log(INT_MAX)/log(3)));
        int ldiv=1162261467;
       // cout<<ldiv<<endl;
        if(ldiv%n==0)
            return true;
        return false;
    }
};