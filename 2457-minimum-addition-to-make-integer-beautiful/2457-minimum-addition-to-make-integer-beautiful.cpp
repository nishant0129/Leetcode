class Solution {
public:
    //const int N =1e13;

    long long int tsum(long long int n)
    {
        long long int sum = 0;
        while (n != 0) {
            sum = sum + n % 10;
            n = n / 10;
            
        }
        return sum;
    }
    long long makeIntegerBeautiful(long long n, int target) {
       // cout<<tsum(n)<<endl;
        if(tsum(n)<=target)
            return 0;
        long long int cnt=0;
        // while(n>0)
        // {
        //     if(tsum(n)<=target)
        //     {
        //         return cnt;
        //     }
        //     cnt++;
        //     n++;
        // }

 
  
      long long count=10;
        long long temp=n;
        
        while(tsum(temp)> target)
        {
            long long rem=n%count;
             temp=n+count-rem;
            
            count*=10;
        }
        return temp-n;

    }
};