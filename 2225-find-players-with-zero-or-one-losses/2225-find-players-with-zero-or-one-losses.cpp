class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res(2,vector<int>());
        map<int,int> um;
        set<int> us;                                
        for(int i=0;i<matches.size();i++)
        {
            int w=matches[i][0],los=matches[i][1];
            um[los]++;                            
            us.insert(w);
            us.insert(los);
        }
        for(auto i:um) 
            if(i.second==1)
                res[1].push_back(i.first);   
        for(auto i=us.begin();i!=us.end();i++)
            if(um.find(*i)==um.end())                              
                res[0].push_back(*i);
        return res;
        
    }
};