class Solution {
public:
    long long int recur(long long int n)
    {
        if(n<=1)
            return 0;
            
        if(n%2==0)
            return 1+recur(n/2);
        else
            return 1+min(recur(n-1),recur(n+1));
    }
    int integerReplacement(int n) {
        return (int)recur(n);
    }
};