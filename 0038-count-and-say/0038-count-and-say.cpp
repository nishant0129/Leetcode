class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        for(int i=1;i<n;i++) {
            string temp="";
            char digit=ans[0];
            int count=0;
            for(int j=0;j<ans.size();j++) {
                if(ans[j]==digit) {
                    count++;
                }else {
                    temp+=to_string(count)+digit;
                    digit=ans[j];
                    count=1;
                }
            }
            // cout<<ans<<endl;
            temp+=to_string(count)+digit;
            ans=temp;
        }
        return ans;
    }
};