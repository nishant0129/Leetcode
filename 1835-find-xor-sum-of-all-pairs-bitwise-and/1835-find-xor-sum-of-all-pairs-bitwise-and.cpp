class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int cxor=0;
        for(auto i:arr2)
            cxor^=i;
        
        int ans=0;
        
        for(auto i:arr1)
           ans^=(int)(i&cxor);
        
        return ans;
    }
};