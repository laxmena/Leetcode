class Solution {
public:
    void compute(stack<int>& st, string token) {
        int arg2 = st.top(); st.pop();
        int arg1 = st.top(); st.pop();
        if(token == "+") st.push(arg1 + arg2);
        else if(token == "-") st.push(arg1 - arg2); 
        else if(token == "*") st.push(arg1 * arg2); 
        else if(token == "/") st.push(arg1 / arg2); 
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto token: tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                compute(st, token);
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};