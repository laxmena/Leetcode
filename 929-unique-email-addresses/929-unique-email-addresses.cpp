class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> unique;
        for(string email: emails) {
            string em = "";
            bool at = false;
            for(int i=0; i<email.length(); i++) {
                char c = email[i];
                if(c == '+') {
                    while(email[i] != '@' && i<email.length()) { i++; }
                    if(!at) at = true;
                    em += email[i];
                    continue;
                }
                if(c == '@') at = true;
                if(c == '.' && !at) continue;
                em += c;
            }
            // cout << em << " ";
            unique.insert(em);
        }
        return unique.size();
    }
};