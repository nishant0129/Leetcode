class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
  
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=tasks.size(); 
        vector<pair<int,pair<int,int >>> vp;
        for(int  i=0;i<n;i++)
        {
            vp.push_back({tasks[i][0],{tasks[i][1],i}});
        }
        
        sort(vp.begin(),vp.end());
        long int i=0;
        long  int ct=vp[0].first;
        long int k=tasks.size();

        vector<int> res;
        while(k--)
        {
            while(i<n && ct>=vp[i].first)
            {
                pq.push({vp[i].second.first,vp[i].second.second});
                i++;
            }
            auto [time,ind]=pq.top();
            pq.pop();
            
            ct+=time;
            res.push_back(ind);
    
            if(pq.empty() && (i<n && ct <vp[i].first ))
                ct=vp[i].first;
            
        }
        return res;
    }
};