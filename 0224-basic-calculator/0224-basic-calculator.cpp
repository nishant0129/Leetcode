//using recursion

// class Solution {
// public:
//    int get_num(string &s, int &i)
//    {
//         int num = 0;
//         while (s[i] >= '0' && s[i] <= '9') 
//         {
//             num *= 10;
//             num += (s[i++] - '0');
//         }
//         return num;
//     }
    
    
//     int get_next(string& s, int& i) 
//     {
//         while (s[i] == ' ') 
//             ++i;
//         int ans;
//         if (s[i] == '(') 
//         {
//             ans = calculate(s, ++i);
//         } 
//         else 
//         {
//             ans = get_num(s, i);
//         }
//         return ans;
//     }
    
    
//     int calculate(string& s, int& i)
//     {
//         int sign = 1, ans = 0;
//         while (i < s.size() && s[i] != ')')
//         {
//             if (s[i] == ' ') 
//             { 
//                 ++i;
//                 continue;
//             }
//             if (s[i] >= '0' && s[i] <= '9')
//             {
//                 ans += get_num(s, i);
//             }
//             else if (s[i] == '+' || s[i] == '-')
//             {
//                 sign = s[i] == '+' ? 1 : -1;
//                 ans += sign * get_next(s, ++i);
//             } 
//             else
//             {
//                 ans += calculate(s, ++i);
//             }
//         }
//         i++;
//         return ans;
//     }
    
    
//     int calculate(string s) 
//     {
//         int i = 0;
//         return calculate(s, i);
//     }
// };


//using stack

class Solution
{
public:
    int calculate(string s) 
    {
        int n = s.size();
        stack<int> st;
        int sum=0,sign=1;
        
        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            if(isdigit(ch))
            {
                int val=0;
                while(i<n && isdigit(s[i]))
                {
                    val = val*10 + (s[i]-'0');
                    i++;
                }
                i--;
                val *= sign;
                sum += val;
                sign = 1;
            }
            else if(ch=='(')
            {
                st.push(sum);
                st.push(sign);
                sum=0;
                sign = 1;
            }
            else if(ch==')')
            {
                sum *= st.top();
                st.pop();
                sum += st.top();
                st.pop();
            }
            else if(ch=='-')
            {
                sign = -1;
            }
            
        }
        return sum;
    }
};