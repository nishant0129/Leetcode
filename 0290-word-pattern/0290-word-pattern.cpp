class Solution {
public:
//     bool wordPattern(string pattern, string s) {
//         set<char>s1;
//         set<string>st;
//         string word;
       
//         vector<string>v;
//         for(auto i:pattern)
//         {
//           s1.insert(i);
//         }
//     for (auto x : s) 
//     {
//         if (x == ' ')
//         {
//             v.push_back(word);
//             st.insert(word);
//             word = "";
//         }
//         else {
//             word = word + x;
//         }
//     }
//     st.insert(word);
//         v.push_back(word);
//          if(pattern.size()!=v.size())
//         {
// return false;}
    
//         if(s1.size()==st.size())
//         {
//            return true;
//         }
//         else
//             return false;
//     }
      bool wordPattern(string pattern, string s) 
      {
        map<char,set<vector<string>>>mp;
   
         map<char,int>m1;
          map<string,int>m2;
          for(auto i:pattern)
              m1[i]++;
        
        string temp="";
     
        int j=0;
          int k=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {   
                m2[temp]++;
                vector<string>v3;
                v3.push_back(temp);
                k++;
               mp[pattern[j++]].insert(v3);
               // s1.clear();
               // i++;
                temp="";
             
            }
            else
             temp+=s[i];
          
        }
           
          if(pattern.size()!=k+1)return false;
          vector<string>v1;
          v1.push_back(temp);
          mp[pattern[j]].insert(v1);
          m2[temp]++;
       for(auto i: mp)
       {
           if(i.second.size()>1)
               return 0; 
       }
          if(m1.size()!=m2.size())
              return false;
       
          return 1;
    }
};