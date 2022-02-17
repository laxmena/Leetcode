
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> domains;
        
        for(auto cp: cpdomains) {
            int space = cp.find(" ");
            int count = stoi(cp.substr(0, space));
            string domain = cp.substr(space+1);
            domains[domain] += count;
            while(domain.find('.') != string::npos) {
                domain = domain.substr(domain.find(".")+1);
                domains[domain] += count;
            }
        }
        
        // convert domains map to result vector
        vector<string> result;
        for(auto& [key, value]: domains) {
            result.push_back(to_string(value) + " " + key); 
        }
        return result;
    }
};