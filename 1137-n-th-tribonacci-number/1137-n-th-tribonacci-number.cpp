class Solution {
public:
    int tribonacci(int n) {
     
        if(n<=3)
        {   if(n==0)
              return 0;
            else if(n==1)
                return 1;
            else if(n==2)
                return 1;
            else 
                return 2;
        }
        int a=1,b=1,c=2,sum=0;
        for(int i=0; i<n-3; i++)
        {
            sum=a+b+c;
            a=b;
            b=c;
            c=sum;
        }
        return sum;
    }
};