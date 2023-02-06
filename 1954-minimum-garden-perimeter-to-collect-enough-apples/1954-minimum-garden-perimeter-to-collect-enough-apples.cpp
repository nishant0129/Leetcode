class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long int low=1,high=1000000,ans=-1;
        while(low<high) {
            long long int ct=(low+high)/2ll;
            // long long int ct=mid;
            if(ct%2) ct-=1;
            
            long long int apples=(ct*(ct+1ll)*(ct+2ll))/2ll;
            if(apples>=neededApples) {
                ans=ct;
                high=ct-1;
            }else{
                low=ct+1;
            }
        }
        return ans*4;
    }
};