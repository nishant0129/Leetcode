// class Solution {
// public:
//     bool ispalindrome(string s)
//     {
//         int i=0,j=s.size()-1;
//         while(i<j)
//         {
//             if(s[i++]!=s[j--]) return false;
//         }
//         return true;
//     }
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         unordered_map<string,int>m;
//         for(int i=0; i<words.size(); i++)
//         {   string s=words[i];
//             reverse(s.begin(),s.end());
//             m[s]=i;
//         }
//         vector<vector<int>>ans;
        
//         for(int i=0; i<words.size();i++)
//         {
//             // string s=words[i];
//             for(int j=0; j<=words[i].size(); j++)
//             {
//                 string str1=words[i].substr(0,j); // prefix 
//                 string str2=words[i].substr(j); // suffix 
//                 cout<<str1<<" "<<str2<<endl;
//                 if(!str1.empty() && ispalindrome(str1) && m.count(str2) && m[str2]!=i)
//                 {
//                     ans.push_back({m[str2],i});
//                 }
//                 if(ispalindrome(str2) && m.count(str1) && m[str1]!=i)
//                 {
//                     ans.push_back({i,m[str1]});
//                 }
//             }
//         }
//         return ans;
//     }
// };
 struct TrieNode
{
    TrieNode *child[26]={};
    int curIndex=-1;
    vector<int> wordIndex;
};
class Solution
{
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    TrieNode *root;
    void insert(string &s, int index)
    {
        TrieNode *cur = root;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            int c = s[i] - 'a';
            if (cur->child[c] == nullptr)
                cur->child[c] = new TrieNode();
            if (isPalindrome(s, 0, i))
                cur->wordIndex.push_back(index);
            cur = cur->child[c];
        }
        cur->wordIndex.push_back(index);
        cur->curIndex = index;
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++)
            insert(words[i], i);
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++)
        {
            TrieNode *cur = root;
            string &s = words[i];
            for (int j = 0; j < s.size(); j++)
            {
                if (cur->curIndex != -1 && cur->curIndex != i && isPalindrome(s, j, s.size() - 1))
                    ans.push_back({i, cur->curIndex});
                cur = cur->child[s[j] - 'a'];
                if (cur == nullptr)
                    break;
            }
            if (cur == nullptr)
                continue;
            for (int j : cur->wordIndex)
            {
                if (i == j)
                    continue;
                ans.push_back({i, j});
            }
        }
        return ans;
    }
};