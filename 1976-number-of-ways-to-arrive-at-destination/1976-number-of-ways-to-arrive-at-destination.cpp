class Solution {
public:
//     void dfs(unordered_map<int,vector<pair<int,int>>>&mp,int src,int &ct,int n,int &ans,vector<bool>&vis,unordered_map<int,int>&mp1)
//     {
//         if(src==n)
//         {
//              mp1[ct]=mp1[ct]%1000000007+1;
//             ans=min(ans,ct);
//             return;
//         }
//         vis[src]=true;
        
//         for(auto child:mp[src])
//         {   
        
//             if(!vis[child.first])
//             {
//                 ct+=child.second;
//                 dfs(mp,child.first,ct,n,ans,vis,mp1);
//                 ct-=child.second;
//                 vis[child.first]=false;
//             }
//         }
        
//     }
    
    int countPaths(int n, vector<vector<int>>& roads) {
       
        unordered_map<int,vector<pair<int,int>>>mp;
       
        
        for(auto v:roads)
        {
            mp[v[0]].push_back({v[1],v[2]});
            mp[v[1]].push_back({v[0],v[2]});
        }
        using pair=pair<long long int,long long int>;
        priority_queue<pair,vector<pair>,greater<pair>>pq;
        vector<long long int>distance(n,LLONG_MAX);
        long long MOD = 1e9 + 7;
        vector <long long int> dp(n+1, 0);
        distance[0]=0;
        pq.push({0,0});
        dp[0]=1;
        while(!pq.empty())
        {
            long long int prevdist= pq.top().first;
            long long int prevnode=pq.top().second;
            pq.pop();
            for(auto i:mp[prevnode])
            {
                long long int nxtdist=i.second;
                long long int nxtnode=i.first;
                if(distance[nxtnode]>prevdist+nxtdist)
                {
                    distance[nxtnode]=prevdist+nxtdist;
                    pq.push({distance[nxtnode],nxtnode});
                    dp[nxtnode]=dp[prevnode]%MOD;
                }
                 else if(distance[nxtnode] == prevdist + nxtdist) {
                    dp[nxtnode] += dp[prevnode];
                    dp[nxtnode] %= MOD;
                }
            }
        }
        // for(auto i:dp)
        //     cout<<i<<" ";
       return (int)dp[n-1];
    }
};