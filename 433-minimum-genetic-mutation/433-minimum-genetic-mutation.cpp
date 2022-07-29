class Solution {
public:
    bool isMutation(string a, string b) {
        int diff = 0;
        for(int i=0; i<a.size() && diff < 2; i++) {
            if(a[i] != b[i]) diff++;
        }
        return diff == 1;
    }
    
    int recurse(string& gene, string& end, int level, vector<string>& bank, map<string, int> visited) {
        
        if(gene == end) {
            // cout << "Gene = End" << gene << " -> " << level << "\n";
            return level;
        }
        
        visited[gene] = level;
        int minVal = INT_MAX;
        
        // cout << "Level " << level << " => " << gene << "\n";
        
        for(string m: bank) {
            if(visited.find(m) != visited.end()) continue;            
            if(isMutation(gene, m)) {
                // cout << "Mutation:  " << gene << " -> " << m << "\n";
                int val = recurse(m, end, level+1, bank, visited);
                // cout << "val => " << val << "\n";
                if(val != -1 && val < minVal) {
                    minVal = val;
                }                
            }
        }
        return minVal == INT_MAX? -1: minVal;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        map<string, int> visited;
        int count = recurse(start, end, 0, bank, visited);
        return count;
    }
};