class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string>q;
        q.push(start);
        int level=0;
        vector<int>vis(bank.size(),0);
        while(!q.empty())
        {
            int sz=q.size();
           
            while(sz--)
            {
                string tmp=q.front();
                q.pop();
                if(end==tmp)
                return level;
                for(int i=0; i<bank.size();i++)
                {
                    if(vis[i])
                        continue;
                    int cnt=0;
                    for(int j=0; j<bank[i].size();j++)
                    {
                        if(tmp[j]!=bank[i][j])
                            cnt++;
                        if(cnt>1)
                            break;
                    }
                    if(cnt==1)
                    { 
                        vis[i]=1;
                        q.push(bank[i]);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};