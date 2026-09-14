#include <vector> 
#include <stack>
#include <string> 

using namespace std; 

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> RPNStack; 

        for (int i=0; i<tokens.size(); i++) { 
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") { 

                int x = RPNStack.top(); 
                RPNStack.pop();

                int y = RPNStack.top();
                RPNStack.pop(); 

                if (tokens[i] == "+") RPNStack.push(y + x);
                else if (tokens[i] == "-") RPNStack.push(y - x);
                else if (tokens[i] == "*") RPNStack.push(y * x);
                else if (tokens[i] == "/") RPNStack.push(y / x);
                
                continue;  
            } 

            RPNStack.push(stoi(tokens[i]));
        }

        return RPNStack.top(); 
    }
};