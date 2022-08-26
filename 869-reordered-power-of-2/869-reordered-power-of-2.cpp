class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        for(int i=0; i<=30; i++)
        {
            string temp=to_string(1<<i);
            sort(temp.begin(),temp.end());
            if(temp==s)return true;
        }
        return false;
    }
};