class Solution {
public:
    bool isMutation(string a, string b) {
        int diff = 0;
        for(int i=0; i<a.size() && diff < 2; i++) {
            if(a[i] != b[i]) diff++;
        }
        return diff == 1;
    }
    
    int recurse(string& gene, string& end, int level, vector<string>& bank, set<string>& visited) {
        
        if(gene == end) {
            return level;
        }
        
        visited.insert(gene);
        int minVal = INT_MAX;
        
        for(string m: bank) {
            if(visited.count(m) > 0) continue;            
            if(isMutation(gene, m)) {
                int val = recurse(m, end, level+1, bank, visited);
                if(val != -1 && val < minVal) {
                    minVal = val;
                }                
            }
        }
        visited.erase(gene);
        return minVal == INT_MAX? -1: minVal;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> visited;
        int count = recurse(start, end, 0, bank, visited);
        return count;
    }
};