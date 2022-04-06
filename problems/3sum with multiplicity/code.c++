class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
//     unordered_map<int, int> m;
//         int res = 0, mod = 1e9 + 7;
//         for (int i = 0; i < arr.size(); i++)
//         {
//             res = (res + m[target - arr[i]]) % mod;
            
//             for (int j = 0; j < i; j++)
//             {
//                 m[arr[i] + arr[j]]++;
//             }
//         }
//         return res;
//     }
        int cnt=0;
       long long int mod=1e9+7,res=0;
        for(int i=0;i<arr.size(); i++)
        { 
            
            vector<int>v(101,0);
            for(int j=i+1; j<arr.size(); j++)
            {
                int k=target -arr[i]-arr[j];
                if(k>=0 && k<=100  &&v[k]>0)
                {
                    res= res%mod +v[k];
                    res%mod;
                }
                v[arr[j]]++;
            }
        }
        return res;
    }
};