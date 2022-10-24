class Solution {
public:
    int recur(vector<string>& arr, string str, int idx) {
        unordered_set<char>s(str.begin(), str.end());
        if (s.size() != ((int)str.length())) 
            return 0;
        int mlen = str.length();
        for (int i = idx; i < arr.size(); i++)
            mlen = max(mlen, recur(arr, str+arr[i], i+1));
        return mlen;
    }
    int maxLength(vector<string>& arr) {
        
        return recur(arr,"",0);
       
    }
};