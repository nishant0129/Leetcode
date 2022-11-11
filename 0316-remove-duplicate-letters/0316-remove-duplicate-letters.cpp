class Solution {
public:
    string removeDuplicateLetters(string s) {
         int n=s.length();
        stack<char> st;
        vector<int> freq(26,0);
        vector<bool> exist(26, false);
        string ans="";
        for(auto c: s)
            freq[c-'a']++;
        for(auto c:s)
        {
            freq[c-'a']--;
            if(exist[c-'a']) 
                continue;
            while(!st.empty() and c<st.top() and freq[st.top()-'a']>0)
            {
                exist[st.top()-'a']=false;
                st.pop();
            }
            st.push(c);
            exist[c-'a']=true;
        }
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans; 
    }
};