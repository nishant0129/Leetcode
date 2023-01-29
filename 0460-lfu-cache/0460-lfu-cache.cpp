class LFUCache {
public:
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    unordered_map<int,int> m;
    unordered_map<int,int> mp1;
    int cap, t = 0;
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) 
    {
        if(m.find(key)==m.end()) return -1;
        put(key,m[key]);
        return m[key];
    }
    
    void put(int key, int value) 
    {
        if(cap==0){
            return;
        }
        if(m.find(key)==m.end()&&m.size()==cap)
        {
            while(m.size()==cap)
            {
                auto x = pq.top();
                if(mp1[x.second.second]==x.first)
                {
                    m.erase(x.second.second);
                    mp1.erase(x.second.second);
                }
                pq.pop();
            }            
        }
        m[key] = value;
        mp1[key]++;
        pq.push({mp1[key],{t++,key}});
    }
};