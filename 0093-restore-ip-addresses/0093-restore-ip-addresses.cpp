class Solution {
public:
    bool is_valid(vector<string>&ip)
    { 
      for(string s:ip)
      {
          if(s.size()>3 || !check(s))
              return false;
      }
        return true;
    }
    bool check(string &s)
    {
         int num=stoi(s);
        if(num>255 || (s[0]=='0' && s.size()!=1))return false;
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        vector<string>ans;
        vector<string>ip(4);
        for(int i=1; i<s.size(); i++)
        {
            ip[0]=s.substr(0,i);
            for(int j=i+1; j<s.size(); j++)
            {
                ip[1]=s.substr(i,j-i);
                
                for(int k=j+1; k<s.size(); k++)
                {
                    ip[2]=s.substr(j,k-j);
                    ip[3]=s.substr(k,n-k);
                    
                     if(is_valid(ip)) 
                        ans.push_back(ip[0]+'.'+ip[1]+'.'+ip[2]+'.'+ip[3]);
                    
                }
            }
        }
        return ans;
    }
};