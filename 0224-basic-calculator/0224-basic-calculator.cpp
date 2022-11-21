class Solution {
public:
    void solve(stack<string>& st) {
        int cur = 0, prev = 0;        
        // cout << "solve \n";
        
        while(!st.empty() && st.top() != "(" ) {
            // cout << "looping.. " << st.top() << "\n";
            
            if(st.top() != "+" && st.top() != "-") {
                prev = prev + cur;
                cur = stoi(st.top()); 
            }
            else if(st.top() == "-") cur *= -1;
            
            st.pop();
        }
        
        if(st.top() == "(") st.pop();
        prev = prev + cur;
        st.push(to_string(prev));
    }
    
    int calculate(string s) {
        stack<string> st;
        s = "(" + s + ")";

        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ') continue;
            
            if(st.empty()) {
                st.push(string(1, s[i]));
                continue;
            }
            
            if(s[i] == ')') {
                solve(st);
                continue;
            }
            
            if(s[i] == '(' || s[i] == '-' || s[i] == '+') {
                if(st.empty() && s[i] == '-')
                    st.push("0");
                st.push(string(1, s[i]));
                // cout << "symbol: " << st.top() << "\n";
                continue;
            }
            
            string val = "";
            if(st.top() != "(" && st.top() != "-" && st.top() != "+") {
                // cout << "not\n";
                val = st.top();
                st.pop();
            }
            val += s[i];
            st.push(val);
            // cout << st.top() << " <= val\n";            

        }
        
        string res = st.top(); st.pop();
        int finalres = stoi(res);
        // if(!st.empty() && st.top())
        return finalres;
    }
};