class Solution {
public:
    void dfs1(int root, int parent, vector<int> adjList[], vector<int> &count, vector<int> &sum)
    {
        for(int child: adjList[root])
        {
            if(child != parent) 
            {
                dfs1(child, root, adjList, count, sum);
                count[root] += count[child];
                sum[root] += sum[child] + count[child]; 
            }
        }
    }
    void dfs2(int root, int parent, vector<int> adjList[], vector<int> &count, vector<int> &sum)
    {
        for(int child: adjList[root])
        {
            if(child != parent) 
            {
                sum[child] = sum[root] - count[child] + (count.size() - count[child]); 
                dfs2(child, root, adjList, count, sum);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
    {
        vector<int> adjList[n];
        vector<int> count(n, 1);
        vector<int> sum(n, 0);
        for(vector<int> edge: edges) 
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        dfs1(0, -1, adjList, count, sum);
        dfs2(0, -1, adjList, count, sum);
        return sum;
    }
};