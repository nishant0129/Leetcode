class Solution
{
    public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) 
    {
        
      int n1=arr1.size(),n2=arr2.size();
        if(n1>n2)
        {
            swap(arr1,arr2);
            swap(n1,n2);
        }
         
        int low=0,high=n1;
        while(low<=high)
        {
            double cut1=(low+high)/2;
            double cut2=(n1+n2)/2-cut1;
            double l1 = cut1 == 0? INT_MIN : arr1[cut1-1];
            double l2 = cut2 == 0? INT_MIN : arr2[cut2-1];
            double r1 = cut1 == n1? INT_MAX : arr1[cut1];
            double r2 = cut2 == n2? INT_MAX : arr2[cut2];
            
            if(l1>r2)
            high=cut1-1;
            else if(l2>r1)
            low=cut1+1;
            else 
            return (n1+n2)%2? min(r1,r2) : (max(l1,l2) + min(r1,r2))/2.0;
        }
        return -1;
    }
        
//  class Solution {
//     vector<int> mergeSortedArrays(vector<int>& nums1, vector<int>& nums2)
//     {
//         vector<int> ans;
//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         int i = 0;
//         int j = 0;
        
//         while(i<n1 && j<n2){
//             if(nums1[i] < nums2[j]){
//                 ans.push_back(nums1[i]);
//                 i++;
//             }
//             else{
//                 ans.push_back(nums2[j]);
//                 j++;
//             }
//         }
        
//         while(i<n1){
//             ans.push_back(nums1[i]);
//             i++;
//         }
        
//         while(j<n2){
//             ans.push_back(nums2[j]);
//             j++;
//         }
//         return ans;
//     }
// public:
     
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
//     {
//         vector<int> merge = mergeSortedArrays(nums1,nums2);
        
//         int n = merge.size();
//         double median;
//         if(n%2 == 1)
//         {
//              median = merge[n/2];
//         }
//         else
//         {
//             double a = merge[n/2];
//             double b = merge[(n/2)-1];
//             median = (a+b)/2;
//         }
//         return median;
//     }
 };