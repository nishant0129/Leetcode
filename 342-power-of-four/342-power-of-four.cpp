// class Solution {
// public:
//     bool isPowerOfFour(int n) {
//         if(n<0)return false;
//         if((n&(n-1))==0 && (n-1)%3==0)
//         {
//             return true;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0)return false;
        int cnt=0;
        if((n&(n-1))==0 )
        {
            while(n)
            {
                n=n>>1;
                cnt++;
            }
            if(cnt%2==1)
            return true;
        }
        return false;
    }
};