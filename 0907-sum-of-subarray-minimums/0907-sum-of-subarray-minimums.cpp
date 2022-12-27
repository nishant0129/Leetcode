class Solution {
public:
    vector<int>leftsmaller(vector<int>&arr)
    {
       int n=arr.size();
       vector<int>lefts(n,1),rights(n,1);
        stack<int>st;
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            int top=st.empty()?-1:st.top();
            //cout<<top<<" "<<i-top<<endl;
              lefts[i]=i-top;
            st.push(i);
        }
        return lefts;
    }
    
   vector<int>rightsmaller(vector<int>&arr)
    {
        int n=arr.size();
       stack<int>st;
       vector<int>rights(n,1);
       for(int i=n-1; i>=0; i--)
        {
            while(st.size() && arr[i] < arr[st.top()]) 
                st.pop();
            if(st.size()) 
                rights[i] = st.top() - i;
            else
                rights[i] = n - i;
            st.push(i);
        }
       return rights;
    }
    int sumSubarrayMins(vector<int>& arr) {
       int n=arr.size();
       vector<int>lefts=leftsmaller(arr);
       vector<int>rights=rightsmaller(arr);
       int res = 0;
        int MOD=1e9+7;
        for(int i=0; i<n; i++)
        {
            long long prod = (lefts[i]*rights[i])%MOD;
            prod = (prod*arr[i])%MOD;
            res = (res + prod)%MOD;
        }
        for(auto i:lefts)
            cout<<i<<" ";
        cout<<endl;
        for(auto i:rights)
            cout<<i<<" ";
        cout<<endl;
        
        return res%MOD;
    }
};