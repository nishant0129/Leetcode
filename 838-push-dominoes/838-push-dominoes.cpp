class Solution {
public:
    string pushDominoes(string dominoes) 
    {
        int n=dominoes.size();
        vector<pair<char,int>>v;
        for(int i=0;i<n;i++)
        {
            if(dominoes[i]!='.')
                v.push_back({dominoes[i],i});
        }
        if(v.size()==0) 
            return dominoes;
        string ans="";
        int tmp=v[0].second;
            tmp++;
        char prevchar;
        int previdx=v[0].second;
        if(v[0].first=='L')
        {
            while(tmp--)
            ans+='L';
            prevchar='L';
        }
        else
        {
            tmp--;
            while(tmp--)
            ans+='.';
            ans+='R';
            prevchar='R';
        }
        for(int i=1;i<v.size();i++)
        {
            char currchar=v[i].first;
            int curridx=v[i].second;
            
            if(prevchar=='L' && currchar=='L')
            {
                for(int j=previdx+1;j<=curridx;j++)
                {
                    ans+='L';
                }
            }
            else if(prevchar=='L' && currchar=='R')
            {
                for(int j=previdx+1;j<=curridx;j++)
                {
                    ans+=dominoes[j];
                }
            }
            else if(prevchar=='R' && currchar=='R')
            {
                for(int j=previdx+1;j<=curridx;j++)
                {
                    ans+='R';
                }
            }
            else if(prevchar=='R' && currchar=='L')
            {
                int len=curridx-previdx+1;
                int mid=(previdx+curridx)/2;
                if(len&1)
                {
                    for(int j=previdx+1;j<mid;j++)
                    {
                        ans+='R';
                    }
                    ans+='.';
                    for(int j=mid+1;j<=curridx;j++)
                    {
                        ans+='L';
                    }
                }
                else 
                {
                    
                    for(int j=previdx+1;j<=mid;j++)
                    {
                        ans+='R';
                    }
                    for(int j=mid+1;j<=curridx;j++)
                    {
                        ans+='L';
                    }
                }
                
            }
            
            previdx=curridx;
            prevchar=currchar;
        }
        if(previdx<n-1)
        {
            if(prevchar=='L')
            {
                for(int i=previdx+1;i<n;i++)
                {
                    ans+='.';
                }
            }
            else {
                for(int i=previdx+1;i<n;i++)
                {
                    ans+='R';
                }
            }
        }
        return ans;
    }
};