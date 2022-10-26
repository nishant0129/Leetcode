class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
       
        // if(nums.size()<=1)
        //     return false;
        // for(int i=0; i<nums.size();i++)
        // {
        //     nums[i]=nums[i]%k;
        // }
        // int csum=0,cnt=0,i=0,n=nums.size();
        // for(int i=0; i<nums.size();i++)
        // {
        //     csum+=nums[i];
        //     if(csum==k)
        //     {
        //         return true;
        //     }
        //     if(mp.find(csum-k)!=mp.end())
        //     {
        //         if(mp[csum-k])
        //             return true;
        //     }
        //     mp[csum]++;
        // }
        // return false;
   
    int sum = 0;
	unordered_map<int, int> mp;
	for(int i=0; i<nums.size(); i++)
	{
		sum += nums[i];
		sum %= k;

		if(sum == 0 && i>0)
            return true;

		if(mp.find(sum) != mp.end())  
		{
			if(i - mp[sum] > 1)
                return true; 
		}
		else 
            mp[sum] = i;
	}

	return false;
}
    
};