class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minitime=0;
       
        for(int i=1; i<colors.size(); i++)
        {
             int maxi=INT_MIN;
            if(colors[i]==colors[i-1])
            {    
                maxi=max(maxi,neededTime[i-1]);
                minitime+=neededTime[i-1];
                while(colors[i]==colors[i-1])
                {
                    maxi=max(maxi,neededTime[i]);
                    minitime+=neededTime[i];
                    i++;
                }
                minitime-=maxi;
            }
        }
        return minitime;
    }
};