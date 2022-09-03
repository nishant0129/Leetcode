class Solution {
public:
    void solve(string s,int n,int k,vector<int>&ans)
    {
        if(s.size()==n)
        {
            ans.push_back(stoi(s));
            return;
        }
        for(int i=0;i<=9;i++)
        {
            // int back=s.back()-'0';
            if(abs(s.back()-'0'-i)==k)
            {
                solve(s+to_string(i),n,k,ans);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        for(int i=1;i<=9;i++)
        {
            solve(to_string(i),n,k,ans);
        }
        return ans;
    }
};


// class Solution {
// public:
//     void solve(int digit,int num,int cnt,int n,int k,vector<int>&ans)
//     {
//        if(cnt==n)
//        {
//            ans.push_back(num);
//            return;
//        }
//        for(int i=0;i<=9;i++)
//        {
//            if(abs(digit-i)==k)
//            {
//                solve(i,num*10+i,cnt+1,n,k,ans);
//            }
//        }
//     }
//     vector<int> numsSameConsecDiff(int n, int k) {
//         vector<int>ans;
//         for(int i=1;i<=9;i++)
//         {
//             solve(i,i,1,n,k,ans);
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     void solve(int n,int k,vector<int>&ans,string s,int j)
//     {
         
//         if(s.size()==n)
//         {
//             ans.push_back(stoi(s));
//             return;
//         }
    
//           if(abs(k,))
//         solve(n,k,ans,s,j-1);
//        s.pop_back();
       
        
//     }
//     vector<int> numsSameConsecDiff(int n, int k) {
//         vector<int>ans;
//         string s="";
//     int j=n;
//    for(int i=1; i<=9;i++)
//     {  
//        s="";
//        s+=to_string(i);
//         solve(n,k,ans,s,j);
//     }
//         return ans;
//     }
// };
// class Solution {
// public:
//     void solve(int curr_digit,vector<int>&ans,)
//     {
           
//     }
//     vector<int> numsSameConsecDiff(int n, int k) {
//         vector<int>ans;
//         vector<int>curr_num;
//         for(int i=1;i<=9;i++) {
            
//         }
//     }
// };