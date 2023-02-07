class Solution {
public:
    bool solve(vector<int>&arr,int mid)
    {
       unordered_map<int,int>mp;
        int i=0,j=0;
        while(j<mid)
            mp[arr[j++]]++;
        if(mp.size()<=2)
            return true;
        while(j<arr.size())
        {
            mp[arr[j]]++;
            mp[arr[i]]--;
            if(mp[arr[i]]<=0)
                mp.erase(arr[i]);
            if(mp.size()<=2 )
            return true;
            
            i++;
            j++;
        }
        return false;
    }
    int totalFruit(vector<int>& fruits) {
        
    int l=1,h=fruits.size(),ans=0;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(solve(fruits,mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
            h=mid-1;
    }
    return ans;
 }
};
    