class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stck; 

        for (auto c: tokens) {
            if (c == "+") {
                int b = stck.top(); stck.pop(); 
                int a = stck.top(); stck.pop(); 
                
                stck.push(a + b); 
            }
            else if (c == "-") {
                int b = stck.top(); stck.pop(); 
                int a = stck.top(); stck.pop();

                stck.push(a - b); 
            }
            else if (c == "*") {
                int b = stck.top(); stck.pop(); 
                int a = stck.top(); stck.pop();

                stck.push(a * b); 
            }
            else if (c == "/") {
                int b = stck.top(); stck.pop(); 
                int a = stck.top(); stck.pop();

                stck.push(a / b); 
            }
            else {
                stck.push(stoi(c)); 
            }
        }

        return stck.top(); 
    }
};

// jab number aye to push kro 
// jab symbolaye to top wale do number nikalo or un pe opr apply karo 
// then push back the result 
// keep doing this untill you hit the last character of the string and that charactre will probably be the opr 
