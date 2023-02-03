class Solution {
public:
    string convert(string s, int nr) {
        int idx=0;
        if(nr==1)
            return s;
        vector<string>res(nr);
        int dir=1;
       for(int i=0; i<s.size(); i++)
       {
             res[idx]+=s[i];
           if(idx==0)
           {
               dir=1;
           }
           if(idx==nr-1)
               dir=-1;
         
           idx+=dir;   
       }
        return accumulate(res.begin(),res.end(),string{});
    }
};