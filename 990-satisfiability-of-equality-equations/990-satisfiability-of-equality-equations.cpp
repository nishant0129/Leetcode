class Solution 
{
    public:
    int uf[26];
    int find(int x) 
    {
        return uf[x] == x ? x : (uf[x] = find(uf[x]));
    }
    bool equationsPossible(vector<string>& equations)
    {
        for (int i = 0; i < 26; ++i) 
            uf[i] = i;
        for (auto eq : equations) 
        {
            if (eq[1] == '=') 
                uf[find(eq[0] - 'a')] = find(eq[3] - 'a'); 
        }
        for (auto eq : equations) 
        {
            if (eq[1] == '!' && find(eq[0] - 'a') == find(eq[3] - 'a')) 
                return false;
        }
        return true;
    }
};