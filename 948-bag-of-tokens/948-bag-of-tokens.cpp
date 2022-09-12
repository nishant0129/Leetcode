class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int curr_power) {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int i=0,j=n-1;
        int curr_score=0;
        int ans=0;
        
        while(i<=j) {
            if(curr_power>=tokens[i]) {
                curr_score+=1;
                curr_power-=tokens[i];
                i++;
                ans=max(ans,curr_score);
            }else {
                if(curr_score) {
                    curr_power+=tokens[j];
                    j--;
                    curr_score--;
                }else {
                    break;
                }
            }
            
        }
        return ans;
    }
};