class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s) {
            if(st.empty()) {
                st.push(c);
                continue;
            }
            char top = st.top();
            if(c == ')' && top == '(') st.pop();
            else if(top == '{' && c == '}') st.pop();
            else if(top == '[' && c == ']') st.pop();
            else st.push(c);
        }
        return st.empty();
    }
};