string str;
class Solution {
public:
 
    static bool comp(const string& a,const string& b)
    {
        int i=0;
        
        while(a[i]==b[i]){
            i++;
            
            if(i==a.length() or i==b.length())
            return a.length()<b.length();
        }
        
        return str.find(a[i])<str.find(b[i]);
    }
    bool isAlienSorted(vector<string>& words, string order) 
    {
        str=order;
        vector<string> temp=words;
        sort(temp.begin(),temp.end(),comp);
        
        return words==temp;
    }
};
