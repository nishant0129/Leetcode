class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        map<int,vector<int>>graph;
         map<pair<int,int>,bool> exists;
        for(auto v:edges)
        {
            int x = v[0];
            int y = v[1];
            exists[{x,y}]=true;
            exists[{y,x}]=true;
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        
        vector<int>od;
        for(auto i:graph)
        {
          if(i.second.size()%2)
              od.push_back(i.first);
        }
         int odd=od.size();
       // cout<<degree<<endl;
          if (odd == 0) 
            return true;
          else if (odd == 2)
          {
            int a = od[0];
            int b = od[1];
            for (int k = 1; k <= n; k++) 
            {
                if (!exists[{a,k}] && !exists[{b,k}])
                    return true;
                
            }
         } 
         else if (odd == 4)
         {
           
            int a = od[0];
            int b = od[1];
            int c = od[2];
            int d = od[3];
 if ((!exists[{a,b}] && !exists[{c,d}]) || (!exists[{a,c}] && !exists[{b,d}]) || (!exists[{a,d}] &&!exists[{b,c}])) 
            {
               return true;
            }
        } 
        return false;         
    }
};