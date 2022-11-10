class Solution {
public:
    void recur(int n,int k,vector<int>&res,int c_num)
    {
        string s=to_string(c_num);
        if(s.size()==n)
        {
            res.push_back(c_num);
            return;
        }
        int last_digit=c_num%10;
        int num1=c_num*10+last_digit+k;
        int num2=c_num*10+last_digit-k;
        if(last_digit+k<=9 && last_digit-k>=0 && num1!=num2)
        {
            recur(n,k,res,num1);
            recur(n,k,res,num2);
        }
        else if(last_digit-k>=0)
              recur(n,k,res,num2);
        else if(last_digit+k<=9)
              recur(n,k,res,num1);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>res;
        for(int i=1;i<=9;i++)
        {
           recur(n,k,res,i);
        }
        return res;
    }
};