class Solution {
public:
    int evalRPN(vector<string>& tokens) {
	stack<int> s;
	for(string &t : tokens) 
		if(t == "+" || t == "-" || t == "*" || t == "/") 
        {
			long long int op1 = s.top();
            s.pop();
			long long int op2 = s.top();
            s.pop();
			if(t == "+") op1 = op2 + op1;
			if(t == "-") op1 = op2 - op1;
			if(t == "/") op1 = op2 / op1;
			if(t == "*") op1 = op2 * op1;   
			s.push(int(op1));
		}
		else s.push(stoi(t));    
        
	return s.top(); 
    }
};