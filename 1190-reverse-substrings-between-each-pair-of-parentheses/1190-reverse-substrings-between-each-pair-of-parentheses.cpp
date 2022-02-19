class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string reverse = "";
        
        for(char c: s) {
            if(c == ')') {
                reverse = "";
                while(st.top() != '(') {
                    char top = st.top();
                    reverse += top;
                    st.pop();
                }
                if(st.top() == '(') st.pop();
                for(int i=0; i<reverse.size(); i++) st.push(reverse[i]);
            } else {
                st.push(c);
            }
        }
        reverse = "";
        while(st.size()) {
            if(st.top() != '(') reverse = st.top() + reverse;
            st.pop();
        }
        return reverse;
    }
};